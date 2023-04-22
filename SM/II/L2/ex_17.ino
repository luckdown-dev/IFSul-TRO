#define DATA 2
#define CLOCK 4
#define LATCH 3

void setup(){
  int vetor[] = {1,1,1,1,0,0,0,0};

  configuraPinos();
  desligaLeds();

  for(int c=0; c<=7; c++){
    digitalWrite(DATA, vetor[c]);
    enviaPulso(CLOCK);
  }

  enviaPulso(LATCH);

}

void loop(){

}

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