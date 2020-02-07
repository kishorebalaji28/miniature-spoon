#include "Talkie.h"
#include "Vocab_US_Large.h"
#include "Vocab_Special.h"

Talkie voice;




int BUZZ =13;
int digitaInput = 6;
// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(digitaInput, INPUT);
  pinMode(BUZZ, OUTPUT);
  
}

// the loop routine runs over and over again forever:
void loop() {
  
  while(digitalRead(digitaInput)==HIGH)
   {
    digitalWrite(BUZZ, HIGH);
    tone(BUZZ,450,2000);
    delay(200);
    noTone(BUZZ);
    delay(500);
     Serial.println("water exists");
     voice.say("WATER");
   }
   while(digitalRead(digitaInput)==LOW)
   {
    digitalWrite(BUZZ,LOW);
      Serial.println("water does not exist");
    }
   
  delay(1000);
}
