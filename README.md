BlueCopter - Arduino Quadcopter
==========
This is a simple arduino quadcopter firmware that uses the ADXL345, L3G4200D (part of the cheap chinese IMU) to maintain a stable flight. 

The main purpose with this firmware is to teach others on how to go about making their own quadcopter firmware. The code is easier to read and follow compared to the more advanced multiwii/arducopter firmwares.

I also have the HMC5883 and BMP085 onboard (as part of the IMU). But haven't implemented them yet.

For questions or more info, check the following: http://forum.arduino.cc/index.php?topic=184503.0

```
Change log:

V1.02 - Implemented a proper receiver expo for smooth response.
        Commenting the line "#define RX_EXPO" will disable the RX-expo.
        
V1.01 - Made the sketch run more efficiently and reduced code size. 
        With this change I managed to find better PID values and thus
        get better/faster stabilization 
        
V1.00 - BlueCopter firmware created!
```
