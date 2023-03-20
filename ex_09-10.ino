#define DATA 2
#define CLOCK 4
#define LATCH 3

void setup(){
  pinMode(DATA, OUTPUT);   //Configuração inicial dos pinos
  pinMode(CLOCK, OUTPUT);
  pinMode(LATCH, OUTPUT);
  
  digitalWrite(CLOCK, 0);  //Configurando estado inicial de clock e latch
  digitalWrite(LATCH, 0);
  
  desligaLeds();  //Configura o estado inicial dos leds
  digitalWrite(DATA, 1);
  
}

void loop(){
  for(int c1=1; c1<=2; c1++){
    pulso(CLOCK);
  }
  delay(500);
  pulso(LATCH);
  digitalWrite(DATA, !digitalRead(DATA));
  
}

void desligaLeds(){
  digitalWrite(DATA, 0);
  
  for(int c1=1; c1<=8; c1++){
    pulso(CLOCK);
  }
  
  pulso(LATCH);
}

void pulso(int pino){
  digitalWrite(pino, 1);
  digitalWrite(pino, 0);
}