float gx_temp[GYRO_MAF_NR]={
  0.0,0.0};
float gy_temp[GYRO_MAF_NR]={
  0.0,0.0};
float gz_temp[GYRO_MAF_NR]={
  0.0,0.0};
int accx_temp=0;
int accy_temp=0;
int accz_temp=0;

unsigned long ts=millis();
unsigned long tf=micros();

void updateSensorVal(){
  if((micros()-tf)>1300){
    updateGyro();  //Update only per 1300us, (~800Hz update rate)
    tf=micros();  
  }
  if((millis()-ts)>20){  //Update only once per 20ms (50Hz update rate)
    updateAcc();
    ts=millis();
  }
  unsigned long t = millis();
  float dt = (float)(t-tp)/1000.0;
  float accx = atan2(accx_temp,accz_temp)*RadToDeg;
  float accy = atan2(accy_temp,accz_temp)*RadToDeg;
  angles[0]=SPLIT*(-gy_aver*dt+angles[0])+(1.0-SPLIT)*accx;
  angles[1]=SPLIT*(gx_aver*dt+angles[1])+(1.0-SPLIT)*accy;
  tp=t; 
}

void updateAcc(){//High pass filter
  int buffer[3]; //Axl buffer
  MPU.getAxlData(buffer);
  buffer[0]=buffer[0]-ACC_X_OFFSET; 
  buffer[1]=buffer[1]-ACC_Y_OFFSET;
  buffer[2]=buffer[2]-ACC_Z_OFFSET;
  accx_temp=(ACC_HPF_NR*accx_temp+(100-ACC_HPF_NR)*buffer[0])/100;
  accy_temp=(ACC_HPF_NR*accy_temp+(100-ACC_HPF_NR)*buffer[1])/100;
  accz_temp=(ACC_HPF_NR*accz_temp+(100-ACC_HPF_NR)*buffer[2])/100;
}

void updateGyro(){
  float buffer[3]; //Gyro buffer
  MPU.getGyroData(buffer);
  for(byte i=0;i<(GYRO_MAF_NR-1);i++){
    gx_temp[i]=gx_temp[i+1];
    gy_temp[i]=gy_temp[i+1];
    gz_temp[i]=gz_temp[i+1];
  }
  gx_temp[GYRO_MAF_NR-1]=(float)(buffer[0]-GYRO_X_OFFSET);
  gy_temp[GYRO_MAF_NR-1]=(float)(buffer[1]-GYRO_Y_OFFSET);
  gz_temp[GYRO_MAF_NR-1]=(float)(buffer[2]-GYRO_Z_OFFSET);
  gyroMAF();
}

void gyroMAF(){//Moving average filter
#if GYRO_HPF_NR > 0
  float gx_old=gx_aver;
  float gy_old=gy_aver;
  float gz_old=gz_aver;
#endif
  gx_aver=0;
  gy_aver=0;
  gz_aver=0;
  for(byte i=0;i<GYRO_MAF_NR;i++){
    gx_aver=gx_aver+gx_temp[i];
    gy_aver=gy_aver+gy_temp[i];
    gz_aver=gz_aver+gz_temp[i];
  }  
  gx_aver=(float)gx_aver/GYRO_MAF_NR;
  gy_aver=(float)gy_aver/GYRO_MAF_NR;
  gz_aver=(float)gz_aver/GYRO_MAF_NR;

#if GYRO_HPF_NR > 0
  gx_aver=(GYRO_HPF_NR*gx_old+(100.0-GYRO_HPF_NR)*gx_aver)/100.0;
  gy_aver=(GYRO_HPF_NR*gy_old+(100.0-GYRO_HPF_NR)*gy_aver)/100.0;
  gz_aver=(GYRO_HPF_NR*gz_old+(100.0-GYRO_HPF_NR)*gz_aver)/100.0;
#endif
}
