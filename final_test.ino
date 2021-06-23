//加功能版
#define NOTE_C3 131
#define NOTE_D3 147
#define NOTE_E3 165
#define NOTE_F3 175
#define NOTE_G3 196
#define NOTE_A3 220
#define NOTE_B3 247
#define NOTE_C4 262

int buttonPin[8] = {2, 3, 4, 5, 6, 7, 8, 9};
int latchPin = 11;
int clockPin = 10;
int dataPin = 12;

int previousState[8] = {1};
int presentState[8] = {1};

byte colDataMatrix[8] = {
  B11111110,
  B11111101,
  B11111011,
  B11110111,
  B11101111,
  B11011111,
  B10111111,
  B01111111
};

byte cleanMatrix[8] ={
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000
};

byte c3[8] = {
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00111100
};

byte d3[8] = {
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B01100111,
  B00000000
};

byte e3[8] = {
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B11011011,
  B00000000,
  B00000000
};

byte f3[8] = {
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B11111111,
  B00000000,
  B00000000,
  B00000000
};

byte g3[8] = {
  B00000000,
  B00000000,
  B00000000,
  B11011011,
  B00000000,
  B00000000,
  B00000000,
  B00000000
};

byte a3[8] = {
  B00000000,
  B00000000,
  B11011011,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000
};

byte b3[8] = {
  B00000000,
  B01111110,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000
};

byte c4[8] = {
  B00111100,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000
};

void setup(){
  pinMode(latchPin,OUTPUT);
  pinMode(clockPin,OUTPUT);
  pinMode(dataPin,OUTPUT);
  
  for(int i = 0; i < 8; i++){
    pinMode(buttonPin[i], INPUT_PULLUP);
  }
}

void piano(){
  for(int i = 0 ; i < 8; i++){
    presentState[i]=digitalRead(buttonPin[i]);
    if(presentState[0]==0){
      tone(13,NOTE_C3,150);
      delay(1);
      previousState[0] = 0;
    } else if(presentState[1]==0){
      tone(13,NOTE_D3,150);
      delay(1);
      previousState[1] = 0;
    } else if(presentState[2]==0){
      tone(13,NOTE_E3,150);
      delay(1);
      previousState[2] = 0;
    } else if(presentState[3]==0){
      tone(13,NOTE_F3,150);
      delay(1);
      previousState[3] = 0;
    } else if(presentState[4]==0){
      tone(13,NOTE_G3,150);
      delay(1);
      previousState[4] = 0;
    } else if(presentState[5]==0){
      tone(13,NOTE_A3,150);
      delay(1);
      previousState[5] = 0;
    } else if(presentState[6]==0){
      tone(13,NOTE_B3,150);
      delay(1);
      previousState[6] = 0;
    } else if(presentState[7]==0){
      tone(13,NOTE_C4,150);
      delay(1);
      previousState[7] = 0;
    }
  }
  for(int i=2; i < 10; i++){
    if(presentState[i]==1 && previousState[i]==0){
      noTone(13);
      previousState[i]=1;
    } 
  }
}

int j=0;

void loop(){
  piano();
  for(int i = 0 ; i < 8; i++){
    presentState[i]=digitalRead(buttonPin[i]);
    if(presentState[0]==1 && previousState[0]==0){
      j++;
      digitalWrite(latchPin,LOW);
      shiftOut(dataPin, clockPin, MSBFIRST, colDataMatrix[i]);
      shiftOut(dataPin, clockPin, MSBFIRST, c3[i]);
      digitalWrite(latchPin,HIGH);
      delay(1);
      previousState[0] = 0;
    } else if(presentState[1]==1 && previousState[1]==0){
      j++;
      digitalWrite(latchPin,LOW);
      shiftOut(dataPin, clockPin, MSBFIRST, colDataMatrix[i]);
      shiftOut(dataPin, clockPin, MSBFIRST, d3[i]);
      digitalWrite(latchPin,HIGH);
      delay(1);
      previousState[1] = 0;
    } else if(presentState[2]==1 && previousState[2]==0){
      j++;
      digitalWrite(latchPin,LOW);
      shiftOut(dataPin, clockPin, MSBFIRST, colDataMatrix[i]);
      shiftOut(dataPin, clockPin, MSBFIRST, e3[i]);
      digitalWrite(latchPin,HIGH);
      delay(1);
      previousState[2] = 0;
    } else if(presentState[3]==1 && previousState[3]==0){
      j++;
      digitalWrite(latchPin,LOW);
      shiftOut(dataPin, clockPin, MSBFIRST, colDataMatrix[i]);
      shiftOut(dataPin, clockPin, MSBFIRST, f3[i]);
      digitalWrite(latchPin,HIGH);
      delay(1);
      previousState[3] = 0;
    } else if(presentState[4]==1 && previousState[4]==0){
      j++;
      digitalWrite(latchPin,LOW);
      shiftOut(dataPin, clockPin, MSBFIRST, colDataMatrix[i]);
      shiftOut(dataPin, clockPin, MSBFIRST, g3[i]);
      digitalWrite(latchPin,HIGH);
      delay(1);
      previousState[4] = 0;
    } else if(presentState[5]==1 && previousState[5]==0){
      j++;
      digitalWrite(latchPin,LOW);
      shiftOut(dataPin, clockPin, MSBFIRST, colDataMatrix[i]);
      shiftOut(dataPin, clockPin, MSBFIRST, a3[i]);
      digitalWrite(latchPin,HIGH);
      delay(1);
      previousState[5] = 0;
    } else if(presentState[6]==1 && previousState[6]==0){
      j++;
      digitalWrite(latchPin,LOW);
      shiftOut(dataPin, clockPin, MSBFIRST, colDataMatrix[i]);
      shiftOut(dataPin, clockPin, MSBFIRST, b3[i]);
      digitalWrite(latchPin,HIGH);
      delay(1);
      previousState[6] = 0;
    } else if(presentState[7]==1 && previousState[7]==0){
      j++;
      digitalWrite(latchPin,LOW);
      shiftOut(dataPin, clockPin, MSBFIRST, colDataMatrix[i]);
      shiftOut(dataPin, clockPin, MSBFIRST, c4[i]);
      digitalWrite(latchPin,HIGH);
      delay(1);
      previousState[7] = 0;
    }
    
    if(j > 8){
      j = 0;
    }
    
    if(presentState[i] == 0){
      previousState[i] = 0;
    }
  } 
}
