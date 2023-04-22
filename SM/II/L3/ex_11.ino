#define DATA 5
#define CLOCK 7
#define LATCH 6

byte vLetra[4];
byte vDisplay[4] = {B11101111, B11011111, B10111111, B01111111};

void setup(){
  configuraDisplay7s();

  exibeJoga();
  for(int c=1; c<=2000; c++){
    atualizaDisplay();
  }

  limpaDisplay();

}

void loop(){
  atualizaDisplay();

}

void exibeJoga(){
  vLetra[0] = {B11101110};
  vLetra[1] = {B10111100};
  vLetra[2] = {B11111100};
  vLetra[3] = {B01110000};
}

void limpaDisplay(){
  for(int c=0; c<=3; c++){
    shiftOut(DATA, CLOCK, LSBFIRST, vDisplay[c]);
    shiftOut(DATA, CLOCK, LSBFIRST, B00000000);
    enviaPulso(LATCH);
  }
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
