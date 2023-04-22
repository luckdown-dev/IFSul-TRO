#define DATA 5
#define CLOCK 7
#define LATCH 6

void setup(){
  configuraDisplay7s();
}

void loop(){
  shiftOut(DATA, CLOCK, LSBFIRST, B11101111); // display ativa com nivel baixo
  shiftOut(DATA, CLOCK, LSBFIRST, B11101110);  // segmentos

  enviaPulso(LATCH);

  shiftOut(DATA, CLOCK, LSBFIRST, B11011111); // display ativa com nivel baixo
  shiftOut(DATA, CLOCK, LSBFIRST, B10001110);  // segmentos

  enviaPulso(LATCH);

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
