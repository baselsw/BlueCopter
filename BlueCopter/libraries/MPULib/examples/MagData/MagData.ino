#include <MPULib.h>
#include <Wire.h>


MPULib MPU;
// the setup routine runs once when you press reset:
void setup() {                
Serial.begin(115200);
while(!Serial);
MPU.init();
}

// the loop routine runs over and over again forever:
void loop() {
int buffer[3];
MPU.getMagData(buffer);
Serial.print("X: ");
Serial.print(buffer[0]);
Serial.print('\t');
Serial.print("Y: ");
Serial.print(buffer[1]);
Serial.print('\t');
Serial.print("Z: ");
Serial.println(buffer[2]);
delay(10);
}
