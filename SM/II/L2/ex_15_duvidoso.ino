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
  
}

void loop(){
  int q1 = 1;
  
  for(int q2=1; q2<=8; q2++){
    
    for(int q=1; q<=8; q++){
      
    if(q==q1){
      digitalWrite(DATA, 1);
    } else {
      digitalWrite(DATA, 0);
    }
      
    pulso(CLOCK);
      
  }
    pulso(LATCH);
    delay(500);
    q1=q1+1;
  }
  
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
