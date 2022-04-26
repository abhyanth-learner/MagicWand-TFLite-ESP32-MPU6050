#include <Arduino.h>
#include <Wire.h>
#include <WireSlave.h>

#define SDA_PIN 21
#define SCL_PIN 22
#define I2C_SLAVE_ADDR 0x04
float Final_data[10];
int i=0;
String rx_data = "";
String data="";
void receiveEvent(int howMany);

void setup()
{
    Serial.begin(115200);

    bool success = WireSlave.begin(SDA_PIN, SCL_PIN, I2C_SLAVE_ADDR);
    if (!success) {
        Serial.println("I2C slave failed");
        while(1) delay(100);
    }

    WireSlave.onReceive(receiveEvent);
}

void loop()
{

    WireSlave.update();

    // let I2C and other ESP32 peripherals interrupts work
    delay(1);
}
void receiveEvent(int howMany)
{
    while (1 < WireSlave.available()) 
    {

        rx_data=(char)WireSlave.read();
//        Serial.print("data");
//        Serial.println(rx_data);
        if(rx_data!=",")
        {
          data.concat(rx_data);
        }
         else{
         // Serial.println(data);
               Final_data[i]=data.toFloat();
          data="";
          i=i+1;
          } 

     
     //Serial.println(data);
     rx_data = "";

    }
    for(int j=0;i<sizeof(Final_data);i++){
     Serial.println(Final_data[j]);  
    } 
    Serial.print("i is");
    Serial.println(i);
//    int x = WireSlave.read();   
//    Serial.println(x);  
//    Serial.print(rx_data);
        
}
