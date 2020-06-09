//Define Fingers

#define hex_1     2   //Right Pinky finger
#define hex_2     3   //Right Ring Finger
#define hex_4     4    //Right Middle Finger
#define hex_8     5   //Right Index Finger

#define hex_16    6   //Left Index Finger
#define hex_32    7   //Left Middle Finger
#define hex_64    8   //Left Ring Finger
#define hex_128   9   //Left Pinky finger

byte Value = 0u;                  //Value of read ASCII Code
unsigned char Character = 0;      //Value displayed as according ASCII character

//define ASCII as array
long Letters[128]={
  "[NULL]",
  "[START OF HEADING]",
  "[START OF TEXT]",
  "[END OF TEXT]",
  "[END OF TRANSMISSION]",
  "[ENQUIRY]",
  "[ACKNOWLEDGE]",
  "[BELL]",
  "[BACKSPACE]",
  "[HORIZONTAL TAB]",
  "[LINE FEED]",
  "[VERTICAL TAB]",
  "[FORM FEED]",
  "[CARRIAGE RETURN]",
  "[SHIFT OUT]",
  "[SHIFT IN]",
  "[DATA LINK ESCAPE]",
  "[DEVICE CONTROL 1]",
  "[DEVICE CONTROL 2]",
  "[DEVICE CONTROL 3]",
  "[DEVICE CONTROL 4]",
  "[NEGATIVE ACKNOWLEDGE]",
  "[SYNCHRONUS IDLE]",
  "[ENG OF TRANS. BLOCK]",
  "[CANCEL]","[ESCAPE]",
  "[FILE SEPERATOR]",
  "[GROUP SEPERATOR]",
  "[RECORD SEPERATOR]",
  "[UNIT SEPERATOR]",
  " ",                                                                                      //[Space]
  "!","Gänsefüßchen","#","$","%","&","'","(",")","*","+",",","-",".","/",
  "0","1","2","3","4","5","6","7","8","9",
  ":",";","<","=",">","?","@",
  "A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z",
  "[","Backslash","]","^","_","Gay Vovel",
  "a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z",
  "{","|","}","~",
  "[DEL]"
  };


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
  Serial.begin(9600);
}

void loop() {

  //Read Inputs
  // Assignment of finger values and sum
  Value = digitalRead(hex_1)*1 + digitalRead(hex_2)*2 + digitalRead(hex_4)*4 + digitalRead(hex_8)*8 + digitalRead(hex_16)*16 + digitalRead(hex_32)*32 + digitalRead(hex_64)*64 + digitalRead(hex_128)*128;

    Serial.println(Value);
    
    Serial.println(Letters[Value]);

    delay(200);
    
}
