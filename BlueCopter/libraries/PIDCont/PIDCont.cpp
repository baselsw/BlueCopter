/*
  Created by Basel Al-Rudainy, 6 april 2013.
  
  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.
*/

#include "Arduino.h"
#include "PIDCont.h"

PIDCont::PIDCont()
{
pError = 0.0;
Ip = 0.000;
kp=0.000;
ki=0.000;
kd=0.000;
Hval=0;
Lval=0;
tp=millis();
}

void PIDCont::ChangeParameters(double mKp, double mKi, double mKd, double mLval, double mHval)
{
kp=mKp;
ki=mKi;
kd=mKd;
Lval = mLval;
Hval = mHval;
}

double PIDCont::Compute(double mError)
{
unsigned long tn = millis();
double dt=(double)(tn-tp);
  double P = (double) kp * mError;
  double D = (double) (kd * (mError-pError) * 1000.0/dt);
  pError = mError;
  double I = (double) (Ip + ki * mError * dt /1000.0);
  double U = (double) (P + I + D);
  Ip = I;
  tp=tn;
  if(U>Hval){
    U = Hval;
  }
  else if (U<Lval){
    U = Lval; 
  }
return U;

}

double PIDCont::Compute(double mError,double dError,double setP)
{
unsigned long tn = millis();
double dt=(double)(tn-tp);
  double P = (double) kp * mError;
  double D = (double) (kd *((setP*1000/dt)-dError));
  pError = mError;
  double I = (double) (Ip + ki * mError * dt /1000.0);
  double U = (double) (P + I + D);
  Ip = I;
  tp=tn;
  if(U>Hval){
    U = Hval;
  }
  else if (U<Lval){
    U = Lval; 
  }
return U;

}

void PIDCont::resetI()
{
Ip=0.0;
tp=millis();
}
