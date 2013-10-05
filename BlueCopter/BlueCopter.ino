/*
  BlueCopter - Quadcopter firmware - V1.0
  
  Created by Basel Al-Rudainy, 6 april 2013.
  
  This firmware is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This firmware is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.
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
