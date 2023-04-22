#define DATA 2
#define CLOCK 4
#define LATCH 3

void setup(){
  configuraPinos();
  desligaLeds();

  for(int c=1; c<=5; c++){
    desligaLeds();
    exibeDoisBits(228);
    delay(500);
    desligaLeds();
    exibeDoisBits(125);
    delay(500);
  }

}

void loop(){
  
}

// *--------* FUNÇÕES *--------* //

void exibeDoisBits(int valor){
  int led = valor & 128;
  shiftOut(DATA, CLOCK, MSBFIRST, led);
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