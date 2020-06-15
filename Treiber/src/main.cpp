#include <Arduino.h>
#include <Keyboard.h>

//Define Fingers

#define hex_1     2   //Right Pinky finger
#define hex_2     3   //Right Ring Finger
#define hex_4     4   //Right Middle Finger
#define hex_8     5   //Right Index Finger

#define hex_16    6   //Left Index Finger
#define hex_32    7   //Left Middle Finger
#define hex_64    8   //Left Ring Finger
#define hex_128   9   //Left Pinky finger

int Value = 0;      //number value according to the Finger-Input

void setup() {
  //setup of the Inputs
  pinMode(hex_1, INPUT); 
  pinMode(hex_2, INPUT);
  pinMode(hex_4, INPUT);
  pinMode(hex_8, INPUT);

  pinMode(hex_16, INPUT);
  pinMode(hex_32, INPUT);
  pinMode(hex_64, INPUT);
  pinMode(hex_128, INPUT);

  Serial.begin(9600); // Baud Rate for control-serial-connnection to 9600
  Keyboard.begin(); //init. of Keyboard Library
}

void loop() {
  
  //Read Inputs
  // Assignment of finger values and sum
  Value = digitalRead(hex_1)*1 + digitalRead(hex_2)*2 + digitalRead(hex_4)*4 + digitalRead(hex_8)*8;// + digitalRead(hex_16)*16 + digitalRead(hex_32)*32 + digitalRead(hex_64)*64 + digitalRead(hex_128)*128;

  if(Value > 0){

    Serial.println(Value);

    Keyboard.write(Value);

    delay(200);

  }


}