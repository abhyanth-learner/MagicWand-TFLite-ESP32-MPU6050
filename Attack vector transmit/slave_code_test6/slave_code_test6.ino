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
void receiveEvent(int howMany)
{
    

        rx_data=(char)WireSlave.read();
//        Serial.print("Recived data:");
//        Serial.println(rx_data);
        if(rx_data=="x")
        {
          while (1 < WireSlave.available()) 
          {
              rx_data=(char)WireSlave.read();
              x.concat(rx_data);
           }
           //Serial.println(x);
           x_final[i]=x.toFloat();
           x="";
        }
        if(rx_data=="y")
        {
          while (1 < WireSlave.available()) 
          {
              rx_data=(char)WireSlave.read();
              y.concat(rx_data);
           }
           y_final[0]=y.toFloat();
           y="";
        }
        if(rx_data=="z")
        {
          while (1 < WireSlave.available()) 
          {
              rx_data=(char)WireSlave.read();
              z.concat(rx_data);
           }
           z_final[0]=z.toFloat();
           z="";
        }
 

        
        Serial.println(x_final[0]);
        
        Serial.println(y_final[0]);
        
        Serial.println(z_final[0]);
//         else{
//         // Serial.println(data);
//               Final_data[i]=data.toFloat();
//          data="";
//          i=i+1;
//          } 

     
     //Serial.println(data);
//     rx_data = "";
//
//    }
//    for(int j=0;j<sizeof(Final_data);j++){
//     Serial.println(Final_data[j]);  
//    } 
//    i=0;
//    Serial.print("i is");
//    Serial.println(i);
//    int x = WireSlave.read();   
//    Serial.println(x);  
//    Serial.print(rx_data);
        
}
