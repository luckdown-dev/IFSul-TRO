#define DATA 5
#define CLOCK 7
#define LATCH 6

byte vLetra[] = {B11101110, B10111100, B11111100, B01110000};
byte vDisplay[] = {B11101111, B11011111, B10111111, B01111111};

void setup(){
  configuraDisplay7s();
  
}

void loop(){
  atualizaDisplay();

}

void atualizaDisplay(){
  for(int c=0; c<=3; c++){
    shiftOut(DATA, CLOCK, LSBFIRST, vDisplay[c]);
    shiftOut(DATA, CLOCK, LSBFIRST, vLetra[c]);
    enviaPulso(LATCH);
  }
}

void configuraDisplay7s(){
  pinMode(DATA, OUTPUT);
  pinMode(CLOCK, OUTPUT);
  pinMode(LATCH, OUTPUT);

  digitalWrite(CLOCK, 0);
  digitalWrite(LATCH, 0);
}

void enviaPulso(int pino){
  digitalWrite(pino, 1);
  digitalWrite(pino, 0);
}
