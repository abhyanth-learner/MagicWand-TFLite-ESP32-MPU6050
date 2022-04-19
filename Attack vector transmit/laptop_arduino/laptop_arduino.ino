int i ;
#include <Wire.h>
void setup() {
  // put your setup code here, to run once:
  Wire.begin();
 Serial.begin(9600);
}

void loop() {

  while(Serial.available()) 
   {
      char ch = Serial.read();
      Serial.println(ch);
      Wire.beginTransmission(0x04);
      Wire.write(ch);
      Serial.println("sent");
      Wire.endTransmission();
        
   }
}
