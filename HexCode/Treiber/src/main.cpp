#include <Arduino.h>
#include <Keyboard.h>

//include display libraries

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

//Define Fingers (change to upperchase!)

#define hex_1     4   //Right Pinky finger
#define hex_2     5   //Right Ring Finger
#define hex_4     6   //Right Middle Finger
#define hex_8     7   //Right Index Finger

#define hex_16    8   //Left Index Finger
#define hex_32    9   //Left Middle Finger
#define hex_64    10  //Left Ring Finger
#define hex_128   11  //Left Pinky finger

#define Prellprotectiontime 100

int Value = 0;      //number value according to the Finger-Input
char Symbol = 0;
unsigned long keystrokedowntime = 0;

bool i;
bool keystroke;

//display SPI (using software)

#define OLED_RESET -1 //Reset PIN to -1 because the display doesn't have one

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT,
  &Wire, OLED_RESET);

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

  i = false;

  Serial.begin(9600); // Baud Rate for control-serial-connnection to 9600
  Keyboard.begin(); //init. of Keyboard Library

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.display();
}

void loop() {

  //Read Inputs
  //Assignment of finger values and sum
  Value = digitalRead(hex_1)*1 + digitalRead(hex_2)*2 + digitalRead(hex_4)*4 + digitalRead(hex_8)*8 + digitalRead(hex_16)*16 + digitalRead(hex_32)*32 + digitalRead(hex_64)*64;// + digitalRead(hex_128)*128;

  Symbol = (char) Value; //cast the Value into a char (Symbol)

  keystroke = digitalRead(hex_128);

  if(keystroke){

   keystrokedowntime = millis();

  }

  if(keystroke && !i){

    Keyboard.write(Value);

    i = true;

  }

  if(!keystroke && millis() - keystrokedowntime > Prellprotectiontime){

    i = false;

  }

//--------------------------------------------------------------------------------------------------------------------------

  display.clearDisplay();


  //define font style
  
  display.setTextSize(3);       // Normal 1:1 pixel scale
  display.setTextColor(WHITE);  // Draw white text

  display.setCursor(5, 10);     // Start at top-left corner

  display.println(Symbol);     //printSymbol to display
  display.display();           //update display with new data

}