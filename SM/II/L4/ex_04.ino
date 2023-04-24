#include <ShiftRegister74HC595.h>

#define botoes A3

#define DATA 2
#define CLOCK 4
#define LATCH 3 

#define BOTAO_0  0
#define BOTAO_1  1
#define BOTAO_2  2
#define NAO_PRESSIONADO -1

ShiftRegister74HC595 leds(1, DATA, CLOCK, LATCH);

unsigned long ultimoRepique = 0;
unsigned long repiqueDelay = 50; // delay do repique

int vbotao_0 = 513, vbotao_1=683, vbotao_2=853;
int led0 = 1, led1 = 1, led2 = 1;

int pin0 = 0;

void setup() {
  pinMode(botoes, INPUT);
  
}

void loop() {
  int dado = leBotaoRepique();
  
  if(dado == BOTAO_0){
    leds.set(0, led0);
    led0 = !led0;
    delay(150);
  }

  if(dado == BOTAO_1){
    leds.set(1, led1);
    led1 = !led1;
    delay(150);
  }

  if(dado == BOTAO_2){
    leds.set(2, led2);
    led2 = !led2;
    delay(150);
  }
}

int leBotao() {
  int botaoLido = analogRead(botoes);

  if(botaoLido >= (vbotao_0 - 10) && botaoLido <= (vbotao_0 + 10)){
    return BOTAO_0;
  } else if(botaoLido >= (vbotao_1 - 10) && botaoLido <= (vbotao_1 + 10)){
    return BOTAO_1;
  } else if(botaoLido >= (vbotao_2 - 10) && botaoLido <= (vbotao_2 + 10)){
    return BOTAO_2;
  } else {
    return NAO_PRESSIONADO;
  }
}

int leBotaoRepique() {
  int botaoLido = leBotao(); // leitura inicial do botão
  if (botaoLido != NAO_PRESSIONADO) { // se o botão foi pressionado
    unsigned long tempoAtual = millis(); // inicia um contador ao ser detecado um botao pressionado
    if (tempoAtual - ultimoRepique > repiqueDelay) { // verifica se o intervalo entre o ultimo repique e o atual ultrapassou o valor definido para o delay
      ultimoRepique = tempoAtual; // atualiza o tempo do último repique
      return botaoLido;
    }
  } else {
    return NAO_PRESSIONADO;
  }
}
