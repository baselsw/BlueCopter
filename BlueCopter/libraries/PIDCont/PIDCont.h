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
#ifndef PIDCont_h
#define PIDCont_h

#include "Arduino.h"

class PIDCont
{
public:
PIDCont();
void ChangeParameters(double mKp, double mKi, double mKd, double mLval, double mHval);
double Compute(double mError);
double Compute(double mError,double dError,double setP);
void resetI();

private:
double kp;
double ki;
double kd;
double pError;
double Ip;
double Lval;
double Hval;
unsigned long tp;
};

#endif
