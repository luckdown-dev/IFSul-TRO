#define DATA 2
#define CLOCK 4
#define LATCH 3

void setup(){
  configuraPinos();
  desligaLeds();

  desligaLeds();
  exibeDoisBits(0x6A);
  delay(1000);
  desligaLeds();
  exibeDoisBits(0x95);
  delay(1000);
  desligaLeds();
  exibeDoisBits(0xEA);
  delay(1000);

}

void loop(){
  
}

// *--------* FUNÇÕES *--------* //

void exibeDoisBits(int valor){  // led1 = bit7; led0 = bit6;
  int bit7 = (valor & 128) >> 1;  // seleciona o valor mais significativo de 8 bits usando o operador AND
  int bit6 = (valor & 64) << 1;   // seleciona o valor mais significativo de 8 bits usando o operador AND

  int leds = bit7 | bit6;  // faz a junção dos valores usando o operador OR (|)

  shiftOut(DATA, CLOCK, LSBFIRST, leds);
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