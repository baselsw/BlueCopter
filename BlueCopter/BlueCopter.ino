/*
  BlueCopter - Quadcopter firmware
  
  Created by Basel Al-Rudainy, 6 april 2013.
  
  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.
  
  Change log:
  V1.02 - Implemented a proper receiver expo for smooth response.
          Commenting the line "#define RX_EXPO" will disable the RX-expo.
  V1.01 - Made the sketch run more efficiently and reduced code size. 
          With this change I managed to find better PID values and thus
          get better/faster stabilization 
  V1.00 - BlueCopter firmware created!
*/

#include "Config.h"
#include <MPULib.h>
#include <Wire.h>
#include <PIDCont.h>
#include <avr/pgmspace.h>


PIDCont PIDroll,PIDpitch,PIDyaw,PIDangleX,PIDangleY;
MPULib MPU;

unsigned long tp;
float angles[2]={
  0.0,0.0};
float gx_aver=0;
float gy_aver=0;
float gz_aver=0;


int setX = 0; //Rate Setpoint for PID
int setY = 0; //Rate Setpoint for PID
int setZ = 0; //Rate Setpoint for PID

volatile int rxVal[6]={1500,1500,1500,0,0,1000};

int throttle=MOTOR_ZERO_LEVEL;
byte rateAngleSwitch = 0;

void setup() {
#ifdef DEBUG  
  Serial.begin(115200);
  while(!Serial);
#endif
  MPU.init();
  motorInit();
  leds_init();
  rxInit();
  motorArm();
  PID_init();
  tp=millis(); //for updateSensorVal
}

void loop() {
  updateSensorVal();
  FlightControl();
#ifdef DEBUG
  debugProcess();
#endif
}
