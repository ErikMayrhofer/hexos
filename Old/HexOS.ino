
//define Fingers

#define hexr_1    2
#define hexr_2    3
#define hexr_4    4
#define hexr_8    5

#define hexl_1    6
#define hexl_2    7
#define hexl_4    8
#define hexl_8    9

#define HIGH  0x1
#define LOW   0x0

int Letter = 0;
long Letters[26] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W"};
long Fingers[8] = {hexl_8, hexl_4, hexl_2, hexl_1, hexr_8, hexr_4, hexr_2, hexr_1};
//long Fingers[8]={0,1,0,0,1,0,0,0};

void setup() {

  //define Fingers as INPUTS

  pinMode(hexr_8, INPUT);
  pinMode(hexr_4, INPUT);
  pinMode(hexr_2, INPUT);
  pinMode(hexr_1, INPUT);

  pinMode(hexl_1, INPUT);
  pinMode(hexl_2, INPUT);
  pinMode(hexl_4, INPUT);
  pinMode(hexl_8, INPUT);
}

void loop() {

  digitalRead(hexr_1);
  digitalRead(hexr_1);
  digitalRead(hexr_1);
  digitalRead(hexr_1);

  digitalRead(hexr_1);
  digitalRead(hexr_1);
  digitalRead(hexr_1);
  digitalRead(hexr_1);

  Fingers[1] = hexl_8;
  Fingers[2] = hexl_4;
  Fingers[3] = hexl_2;
  Fingers[4] = hexl_1;

  Fingers[5] = hexl_8;
  Fingers[6] = hexl_4;
  Fingers[7] = hexl_2;
  Fingers[8] = hexl_1;

  Letter = Fingers[1] * 128 + Fingers[2] * 64 + Fingers[3] * 32 + Fingers[4] * 16 + Fingers[5] * 8 + Fingers[6] * 4 + Fingers[7] * 2 + Fingers[8] * 1 - 64;

  Serial.write(Letters[Letter]);

}
