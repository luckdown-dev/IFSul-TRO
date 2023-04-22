#define DATA 2
#define CLOCK 4
#define LATCH 3

void setup(){
  configuraPinos();
  desligaLeds();
  
  shiftOut(DATA, CLOCK, MSBFIRST, B11010111);
  enviaPulso(LATCH);
  delay(1000);
  desligaLeds();
  delay(250);
  
}

void loop(){

}

// *--------* FUNÇÕES *--------* //

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
