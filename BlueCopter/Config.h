// -----Other Config---------

#define SAFE    //Arming procedure

//---------------------------


//-------PID Config----------

#define ROLL_PID_KP  0.250
#define ROLL_PID_KI  0.950
#define ROLL_PID_KD  0.011
#define ROLL_PID_MIN  -50.0
#define ROLL_PID_MAX  50.0

#define PITCH_PID_KP  0.250
#define PITCH_PID_KI  0.950
#define PITCH_PID_KD  0.011
#define PITCH_PID_MIN  -50.0
#define PITCH_PID_MAX  50.0

#define YAW_PID_KP  0.680
#define YAW_PID_KI  0.500
#define YAW_PID_KD  0.0001
#define YAW_PID_MIN  -50.0
#define YAW_PID_MAX  50.0

#define ANGLEX_KP 5.0
#define ANGLEX_KI 0.02
#define ANGLEX_KD -0.015
#define ANGLEX_MIN -100.0
#define ANGLEX_MAX 100.0

#define ANGLEY_KP 5.0
#define ANGLEY_KI 0.02
#define ANGLEY_KD -0.015
#define ANGLEY_MIN -100.0
#define ANGLEY_MAX 100.0

//-------------------------



//.....RX Config............
#define THROTTLE_RMIN  1104
#define THROTTLE_RMAX  1892
#define THROTTLE_WMIN  MOTOR_ARM_START
#define THROTTLE_WMAX  MOTOR_MAX_LEVEL

#define ROLL_RMIN  1040
#define ROLL_RMAX  1976
#define ROLL_WMIN  -15
#define ROLL_WMAX  15

#define PITCH_RMIN  1140
#define PITCH_RMAX  1932
#define PITCH_WMIN  -15
#define PITCH_WMAX  15

#define YAW_RMIN  1028
#define YAW_RMAX  2004
#define YAW_WMIN  -45
#define YAW_WMAX  45

#define RKNOB_RMIN  1008
#define RKNOB_RMAX  2036
#define RKNOB_WMIN  -230
#define RKNOB_WMAX  230

#define LKNOB_RMIN  976
#define LKNOB_RMAX  2004
#define LKNOB_WMIN  0
#define LKNOB_WMAX  500

#define RX_RATE_SENSITIVITY  3
#define RX_ANGLE_DAMPNING  20.0  //D-term dampning
#define RX_EXPO
//..........................

//----Debug Config---------
//#define DEBUG
//#define DEBUG_ANGLES
//#define DEBUG_GYRO
//#define DEBUG_PID
//#define DEBUG_RX
//#define DEBUG_SERIAL_CHART

//-------------------------


//*********Sensor Config****************

#define ACC_X_OFFSET  19
#define ACC_Y_OFFSET  7
#define ACC_Z_OFFSET  -73

#define GYRO_X_OFFSET  1.418431
#define GYRO_Y_OFFSET  -1.05606
#define GYRO_Z_OFFSET  -0.54401


#define SPLIT  0.99 //COMP-filter nr
#define RadToDeg 180.0/PI 
#define  ACC_HPF_NR  98  //high pass filter nr
#define  GYRO_HPF_NR 0   //high pass filter nr
#define  GYRO_MAF_NR  2  //Moving average filter nr
//*************************************




//***********MOTOR CONFIG**************

//Motor PWM Levels
#define MOTOR_ZERO_LEVEL  125
#define MOTOR_ARM_START  140
#define MOTOR_MAX_LEVEL  254


//Motor Pins
#define MOTOR0  6
#define MOTOR1  10
#define MOTOR2  5
#define MOTOR3  9


//*************************************




//***********LED CONFIG**************

//LED Pin
#define LED13  13
//*************************************



//.......RX PINS............
#define RX_PIN_ROLL  16     //PCINT2
#define RX_PIN_PITCH  14    //PCINT3
#define RX_PIN_YAW  15      //PCINT1
#define RX_PIN_THROTTLE  7  //INT6
#define RX_PIN_AUX1  8      //PCINT4
#define RX_PIN_AUX2  0      //INT2
#define RX_INT_AUX2  2
#define RX_INT_THROTTLE 4
//........................
