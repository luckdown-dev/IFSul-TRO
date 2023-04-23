#define DATA 5
#define CLOCK 7
#define LATCH 6

byte vLetra[4];
byte vDisplay[4] = {B11101111, B11011111, B10111111, B01111111};
byte vDigito[10] = {B11111100, B01100000, B11011010, B11110010, B01100110, B10110110, B10111110, B11100000, B11111110, B11100110};

void setup(){
  configuraDisplay7s();

}

void loop(){
  for(int c=0; c<=2000; c++){
    exibeDecimal(c);
    atualizaDisplayComDelay(100);
  }

}

void exibeDecimal(int valor){
  int unidade = 1000;
  int resto, display, anterior=0;

  for(int c=3; c>=0; c--){
    resto = valor % unidade;
    display = (valor - resto) / unidade;
    anterior = anterior + display;

    if(resto!=0 && anterior==0){
      vLetra[c] = B00000000;
    } else{
      vLetra[c] = vDigito[display];
    }

    valor = resto;
    unidade = unidade / 10;
  }
}

void exibeUnidade(int numero){
  while(numero>9){
    numero = numero % 10;
  }

  vLetra[0] = vDigito[numero];

  for(int c=1; c<=3; c++){
    vLetra[c] = B00000000;
  }

}

void atualizaDisplayComDelay(unsigned long duracao){
  unsigned long tempoFinal;

  tempoFinal = millis() + duracao;
  while (millis() < tempoFinal){
    atualizaDisplay();
  }

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
