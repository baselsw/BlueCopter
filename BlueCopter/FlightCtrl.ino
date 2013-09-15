void FlightControl(){
  //  int kpr;
  //  int kpi;
  //  int kpd;
  //  kpr=map(rxVal[3],RKNOB_RMIN,RKNOB_RMAX,RKNOB_WMIN,RKNOB_WMAX);
  //  kpd=map(rxVal[4],LKNOB_RMIN,LKNOB_RMAX,LKNOB_WMIN,LKNOB_WMAX);
  //  PIDangleX.ChangeParameters(ANGLEX_KP,0,(float)(kpr/1000.0),ROLL_PID_MIN,ROLL_PID_MAX);
  //  PIDangleY.ChangeParameters(ANGLEY_KP,0,(float)(kpr/1000.0),PITCH_PID_MIN,PITCH_PID_MAX);
  //  PIDyaw.ChangeParameters(YAW_PID_KP,(float)(kpi/1000.0),YAW_PID_KD,YAW_PID_MIN,YAW_PID_MAX);
#ifdef SAFE
  if(rxVal[5]<1100){
    motorArm();
  }
#endif

  if(rxVal[4]<1500){
    rateAngleSwitch=0;
    leds_status(0);
  }
  else{
    rateAngleSwitch=1;
    leds_status(1);
    PIDangleX.resetI();
    PIDangleY.resetI();
  }

  throttle=map(rxVal[5],THROTTLE_RMIN,THROTTLE_RMAX,THROTTLE_WMIN,THROTTLE_WMAX);
  setZ=map(rxVal[0],YAW_RMIN,YAW_RMAX,YAW_WMAX,YAW_WMIN);


  if (rateAngleSwitch == 0){
    setX=map(rxVal[1],ROLL_RMIN,ROLL_RMAX,ROLL_WMIN,ROLL_WMAX);
    setY=map(rxVal[2],PITCH_RMIN,PITCH_RMAX,PITCH_WMAX,PITCH_WMIN);
  }
  else{
    setX=map(rxVal[1],ROLL_RMIN,ROLL_RMAX,ROLL_WMIN*RX_RATE_SENSITIVITY,ROLL_WMAX*RX_RATE_SENSITIVITY);
    setY=map(rxVal[2],PITCH_RMIN,PITCH_RMAX,PITCH_WMAX*RX_RATE_SENSITIVITY,PITCH_WMIN*RX_RATE_SENSITIVITY); 
  }


#ifdef RX_EXPO
  if((rxVal[1]>1480) & (rxVal[1]<1520)) setX=0.0;
  if((rxVal[2]>1480) & (rxVal[2]<1520)) setY=0.0;
  if((rxVal[0]>1480) & (rxVal[0]<1520)) setZ=0.0;
#endif

  if (rateAngleSwitch == 0){
    setX=(int)PIDangleX.Compute((float)setX+angles[0],gy_aver,(float)setX/RX_ANGLE_DAMPNING);
    setY=(int)PIDangleY.Compute((float)setY-angles[1],gx_aver,(float)setY/RX_ANGLE_DAMPNING);
  }
  int PIDroll_val= (int)PIDroll.Compute((float)setX-gy_aver);
  int PIDpitch_val= (int)PIDpitch.Compute((float)setY-gx_aver);
  int PIDyaw_val= (int)PIDyaw.Compute((float)setZ-gz_aver);


  int m0_val=throttle+PIDroll_val+PIDpitch_val+PIDyaw_val;
  int m1_val=throttle-PIDroll_val+PIDpitch_val-PIDyaw_val;
  int m2_val=throttle+PIDroll_val-PIDpitch_val-PIDyaw_val;
  int m3_val=throttle-PIDroll_val-PIDpitch_val+PIDyaw_val;

  analogWrite(MOTOR0,m0_val);
  analogWrite(MOTOR1,m1_val);
  analogWrite(MOTOR2,m2_val);
  analogWrite(MOTOR3,m3_val);

}
