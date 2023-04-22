#define DATA 2
#define CLOCK 4
#define LATCH 3

void setup(){
  configuraPinos();
  desligaLeds();

  for(int i=1; i<=5; i++){
    desligaLeds();
    exibeBitMSB(228);
    delay(500);
    desligaLeds();
    exibeBitMSB(125);
    delay(500);
  }

}

void loop(){

}

// *--------* FUNÇÕES *--------* //

void exibeBitMSB(int valor){
  int estado = valor & 128;
  shiftOut(DATA, CLOCK, LSBFIRST, estado);
  enviaPulso(LATCH);
}

void configuraPinos(){
  pinMode(DATA, OUTPUT);
  pinMode(CLOCK, OUTPUT);
  pinMode(LATCH, OUTPUT);

  digitalWrite(CLOCK, 0);
  digitalWrite(LATCH, 0);
}

void desligaLeds(){
  shiftOut(DATA, CLOCK, MSBFIRST, B00000000);
  enviaPulso(LATCH);
}

void enviaPulso(int pino){
  digitalWrite(pino, 1);
  digitalWrite(pino, 0);
}