#define DATA 2
#define CLOCK 4
#define LATCH 3

void setup(){
  configuraPinos();
  desligaLeds();

  shiftOut(DATA, CLOCK, MSBFIRST, B11110000);  // MSBFIRST => inicia pelo mais significativo 
  enviaPulso(LATCH);

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
  digitalWrite(DATA, 0);

  for(int c=1; c<=8; c++){
    enviaPulso(CLOCK);
  }

  enviaPulso(LATCH);
}

void enviaPulso(int pino){
  digitalWrite(pino, 1);
  digitalWrite(pino, 0);
}