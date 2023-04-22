#define DATA 2
#define CLOCK 4
#define LATCH 3

void setup(){
  configuraPinos();
  enviaParaLeds(0);

  for(int c=1; c<=15; c++){
    enviaParaLeds(c);
    delay(250);
    enviaParaLeds(0);
    delay(250);
  }
  
}

void loop(){
  
}

// *--------* FUNÇÕES *--------* //

void enviaParaLeds(int valor){
  int leds = valor & 255;  // faz a seleção de quais valores estão em nivel lógico alto usando o operador AND (&)

  shiftOut(DATA, CLOCK, MSBFIRST, leds);
  enviaPulso(LATCH);
}

void configuraPinos(){
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