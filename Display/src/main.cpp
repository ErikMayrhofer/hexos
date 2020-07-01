#include <Arduino.h>

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

//Define Fingers

#define hex_1     2   //Right Pinky finger
#define hex_2     3   //Right Ring Finger
#define hex_4     4    //Right Middle Finger
#define hex_8     5   //Right Index Finger

#define hex_16    6   //Left Index Finger
#define hex_32    7   //Left Middle Finger
#define hex_64    8   //Left Ring Finger
#define hex_128   9   //Left Pinky finger

#define OLED_MOSI   9
#define OLED_CLK   10
#define OLED_DC    11
#define OLED_CS    12
#define OLED_RESET 13

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT,
  OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

int Value = 0;      //number value according to the Finger-Input
char Symbol = 0;    //according ascii symbol to Value

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
}

void testdrawchar(void) {
  display.clearDisplay();

  display.setTextSize(1);      // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE); // Draw white text
  display.setCursor(0, 0);     // Start at top-left corner
  display.cp437(true);         // Use full 256 char 'Code Page 437' font

  // Not all the characters will fit on the display. This is normal.
  // Library will draw what it can and the rest will be clipped.
  for(int16_t i=0; i<256; i++) {
    if(i == '\n') display.write(' ');
    else          display.write(i);
  }

  display.display();
  delay(2000);
}

void loop() {
  
  //Read Inputs
  // Assignment of finger values and sum
  Value = digitalRead(hex_1)*1 + digitalRead(hex_2)*2 + digitalRead(hex_4)*4 + digitalRead(hex_8)*8 + digitalRead(hex_16)*16 + digitalRead(hex_32)*32 + digitalRead(hex_64)*64 + digitalRead(hex_128)*128;

  Symbol = (char) Value;

    Serial.println(Value);

    Serial.println(Symbol);

    delay(200);

}