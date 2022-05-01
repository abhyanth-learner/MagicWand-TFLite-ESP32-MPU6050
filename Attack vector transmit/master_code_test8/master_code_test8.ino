#include <Arduino.h>
#include <Wire.h>
#include <WirePacker.h>

#define SDA_PIN 21
#define SCL_PIN 22
#define I2C_SLAVE_ADDR 0x04
String y;
char buf[50];
char ch = 0;
char i = 0;
void setup()
{
    Serial.begin(115200);           // start serial for output
    Wire.begin(SDA_PIN, SCL_PIN);   // join i2c bus
}

void loop()
{
    static unsigned long lastWireTransmit = 0;
    WirePacker packer;
  
     while(Serial.available())
     {
        y = Serial.readString();
//        Serial.print(y);

        y.toCharArray(buf, 50);
//        Serial.println(y[0]);
//        packer.write(y[0]);
//        packer.end();
        
        for (int i=0; i<sizeof(y); i++)
        {
//          Serial.println(y[i]);
          packer.write(y[i]);
        }
        packer.end();
        
        // now transmit the packed data
        Wire.beginTransmission(I2C_SLAVE_ADDR);
        while (packer.available()) {    // write every packet byte
//            int a = packer.read();
//            Serial.println(a);
//            Wire.write(packer.read());
            Wire.write(packer.read());
        }
        
        Wire.endTransmission(); 
     }

//    // send data to WireSlave device every 1000 ms
//    if (millis() - lastWireTransmit > 1000) {
//       y = ch;
//        // first create a WirePacker that will assemble a packet
//        WirePacker packer;
//
//        // then add data the same way as you would with Wire
////        packer.write("y is ");
//        packer.write(y);
//        Serial.println(y);
//        // after adding all data you want to send, close the packet
//        packer.end();
//
//        // now transmit the packed data
//        Wire.beginTransmission(I2C_SLAVE_ADDR);
//        while (packer.available()) {    // write every packet byte
//            Wire.write(packer.read());
//        }
//        Wire.endTransmission();         // stop transmitting
//
//        y++;
//        lastWireTransmit = millis();
//    }
}
