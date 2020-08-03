#include <Arduino.h>

//include display libraries

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

//Define Fingers

#define hex_1     2   //Right Pinky finger
#define hex_2     3   //Right Ring Finger
#define hex_4     4    //Right Middle Finger
#define hex_8     5   //Right Index Finger

#define hex_16    6   //Left Index Finger
#define hex_32    7   //Left Middle Finger
#define hex_64    8   //Left Ring Finger
#define hex_128   9   //Left Pinky finger

//display SPI (using software)

#define OLED_RESET -1 //Reset PIN to -1 because the display doesn't have one

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT,
  &Wire, OLED_RESET);

//Hexhands finger to Char translation variables

int Value = 0;      //number value according to the Finger-Input
char Symbol = 0;    //according ascii symbol to Value

int display_spacing = 5; //defines the spce between the left side of the display and the current letter in pixels

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

  //Serial.begin(9600); // Baud Rate for control-serial-connnection to 9600

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.display();
}

//draw char on display

void drawchar() {
  display.clearDisplay();

  display.setTextSize(1);      // Normal 1:1 pixel scale
  display.setTextColor(WHITE); // Draw white text
  display.setCursor(5, 10);     // Start at top-left corner
  display.println("Hello World");

  display.display();
}

void loop() {
  
  //Read Inputs
  // Assignment of finger values and sum
  Value = digitalRead(hex_1)*1 + digitalRead(hex_2)*2 + digitalRead(hex_4)*4 + digitalRead(hex_8)*8 + digitalRead(hex_16)*16 + digitalRead(hex_32)*32 + digitalRead(hex_64)*64 + digitalRead(hex_128)*128 + 64;

  Symbol = (char) Value;



  display.clearDisplay();


  //define font style
  display.setTextSize(3);      // Normal 1:1 pixel scale
  display.setTextColor(WHITE); // Draw white text

  display.setCursor(display_spacing, 10);     // Start at top-left corner

  display.println(Symbol); //printSymbol to display
  display.display(); //update display with new data

  //display_spacing = display_spacing + 15;



//output
  // Serial.println(Value);

  //Serial.println(Symbol);

  //delay(200);

}