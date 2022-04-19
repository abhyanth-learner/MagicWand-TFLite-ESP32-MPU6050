#include <Arduino.h>
#include <Wire.h>
#include <WireSlave.h>

#define SDA_PIN 21
#define SCL_PIN 22
#define I2C_SLAVE_ADDR 0x04

void receiveEvent(int howMany);

void setup()
{
    Serial.begin(9600);

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
//    while (1 < WireSlave.available()) 
//    {
//        char c = WireSlave.read();  
//        Serial.print(c);            
//    }

    int x = WireSlave.read();   
    Serial.println(x);          
}
