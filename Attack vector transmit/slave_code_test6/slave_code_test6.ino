#include <Arduino.h>
#include <Wire.h>
#include <WireSlave.h>

#define SDA_PIN 21
#define SCL_PIN 22
#define I2C_SLAVE_ADDR 0x04
float Final_data[20];
int i=0;
String rx_data = "";
String x="";
String y="";
String z="";
float x_final[10];
float y_final[10];
float z_final[10];
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
