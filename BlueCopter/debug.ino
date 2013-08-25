void debugProcess(){
  #ifdef DEBUG_ANGLES
   Serial.print("XT:");
  Serial.print((float)(angles[0]));
  Serial.print('\t');
  Serial.print("YT:");
  Serial.print((float)(angles[1]));
  Serial.print('\t');
  #endif
  #ifdef DEBUG_GYRO
  Serial.print("GX:");
  Serial.print((float)(gx_aver));
  Serial.print('\t');
  Serial.print("GY:");
  Serial.print((float)(gy_aver));
  Serial.print('\t');
  Serial.print("GZ:");
  Serial.print((float)(gz_aver));
  Serial.print('\t');
  #endif
  #ifdef DEBUG_PID
  Serial.print("Kp:");
  Serial.print((int)(kpr));
  Serial.print('\t');
  Serial.print("Ki:");
  Serial.print((int)(kpi));
  Serial.print('\t');
  Serial.print("Kd:");
  Serial.print((int)(kpd));
  Serial.print('\t');
  #endif
  #ifdef DEBUG_RX
  Serial.print(F("Yaw:"));
  Serial.print(rxVal[0]);
  Serial.print('\t');
  Serial.print(F("Roll:"));
  Serial.print(rxVal[1]);
  Serial.print('\t');
  Serial.print(F("Pitch:"));
  Serial.print(rxVal[2]);
  Serial.print('\t');
  Serial.print(F("AUX1:"));
  Serial.print(rxVal[3]);
  Serial.print('\t');
  Serial.print(F("AUX2:"));
  Serial.print(rxVal[4]);
  Serial.print('\t');  
  Serial.print(F("Throttle:"));
  Serial.print(rxVal[5]);
  Serial.print('\t');    
  #endif
  
  #ifdef DEBUG_SERIAL_CHART
  Serial.print(angles[0]);
  Serial.print(',');
  Serial.print(angles[1]);  
  #endif
  
  Serial.print('\n');
  
}
