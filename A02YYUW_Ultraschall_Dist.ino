#include <OneWire.h>

// Beispiel mit einem Wemos D1 (Alf 2020)
// Die Anschlüsse werden Softwareseitig erstellt.
/*
 *Wiki zum Sensor und Codequelle: 
 *https://wiki.dfrobot.com/A02YYUW%20Waterproof%20Ultrasonic%20Sensor%20SKU:%20SEN0311
 */

#include <SoftwareSerial.h> 
#define mess_TX A0 // Trage deinen Anschluss für das blaue Kabel ein 
#define mess_RX A1 // Trage deinen Anschluss für das grüne Kabel ein
 SoftwareSerial mySerial(mess_RX,mess_TX); // RX, TX 
 unsigned char data[4]={}; 
 float distance; 
 
 void setup() { 
  Serial.begin(115200); 
  mySerial.begin(9600); } 
  
  void loop() { 
    do{ 
      for(int i=0;i<4;i++) { 
        data[i]=mySerial.read(); 
        } 
      }
      
      while(mySerial.read()==0xff); 
      mySerial.flush(); 
      if(data[0]==0xff) { 
        int sum; 
        sum=(data[0]+data[1]+data[2])&0x00FF; 
        
        if(sum==data[3]) { 
          distance=(data[1]<<8)+data[2]; 
          
          if(distance>300) { //Minimaldistanz auf 300mm gesetzt
          Serial.print("distance="); 
          Serial.print(distance/10); 
          Serial.println("cm"); 
          }
          else { 
                Serial.println("Below the lower limit"); 
               } 
       }
            else 
            Serial.println("ERROR"); 
      } 
      delay(150); 
  }


/*
A01NYUB Wasserdichter Ultraschall Distanz Sensor

    Hersteller DFRobot
    Artikelnr. 421142
    Verfügbarkeit Lagernd

    35,90CHF
    Netto 33,33CHF

Menge

0 Bewertungen / + Bewertung
*/
