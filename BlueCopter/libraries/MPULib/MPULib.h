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
#ifndef MPULib_h
#define MPULib_h

#include "Arduino.h"
#include "Wire.h"

// <---------ADXL345-------------->
#define ADXL_addr 0x53  //addr-pin LOW

#define REG_DATA_FORMAT  0x31
#define REG_PWR_CTL  0x2D
#define REG_BW_RATE	0x2C

#define DATAX0  0x32  //LSB
#define DATAX1  0x33  //MSB
#define DATAY0  0x34  //LSB
#define DATAY1  0x35  //MSB
#define DATAZ0  0x36  //LSB
#define DATAZ1  0x37  //MSB
// <-------------------------------->

// <---------L3G4200D-------------->

#define L3G4_addr 0x69  //SDO-pin HIGH

#define CTRL_REG1  0x20
#define CTRL_REG2	0x21
#define CTRL_REG4  0x23
#define CTRL_REG5 0x24
#define L3G4_HPF	0x13
#define L3G4_LPF	0x34
#define L3G4_BW_ENAX	0x8F
#define MODE_250  0x00
#define MODE_500  ((0x01)<<4) 
#define MODE_2000 ((0x03)<<4) 
#define SCALE_250  (8.75/1000.0)
#define SCALE_500  (17.5/1000.0)
#define SCALE_2000  (70.0/1000.0)

#define READALLSIX  0x28 | (1 << 7)
#define OUT_X_L  0x28
#define OUT_X_H  0x29
#define OUT_Y_L  0x2A
#define OUT_Y_H  0x2B
#define OUT_Z_L  0x2C
#define OUT_Z_H  0x2D
// <-------------------------------->

// <---------HMC5883-------------->
#define HMC_addr	0x1E
#define HMC_mode_reg	0x02
#define HMC_contm_val	0x00
#define HMC_X_MSB	0x03
// <-------------------------------->

class MPULib
{
public:
MPULib();
void init();
void getAxlData(int buff[]);
void getGyroData(float buff[]);
void getMagData(int buff[]);
private:
void readCmd(byte addr,byte reg,byte num,byte buff[]);
void writeCmd(byte addr, byte reg, byte val);
};

#endif
