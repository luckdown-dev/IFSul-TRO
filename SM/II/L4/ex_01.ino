#include <ShiftDisplay.h>

#define botoes A3

#define vermelho A0
#define verde A1
#define azul A2

#define BOTAO_0  0
#define BOTAO_1  1
#define BOTAO_2  2
#define NAO_PRESSIONADO -1

ShiftDisplay display7s(COMMON_CATHODE, 4);

int vbotao_0 = 683, vbotao_1=755, vbotao_2=935;

void setup() {
  pinMode(botoes, INPUT);
  pinMode(vermelho, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(azul, OUTPUT);

}

void loop() {

  int botao = leBotao();
  if(botao == BOTAO_2){
    digitalWrite(vermelho, 1);
  } else {
    digitalWrite(vermelho, 0);
  }

  if(botao == BOTAO_1){
    digitalWrite(verde, 1);
  } else {
    digitalWrite(verde, 0);
  }

  if(botao == BOTAO_0){
    digitalWrite(azul, 1);
  } else {
    digitalWrite(azul, 0);
  }

}

int leBotao() {
  int dado = analogRead(botoes);

  if(dado >= (vbotao_0 - 10) && dado <= (vbotao_0 + 10)){
    return BOTAO_0;
  } else if(dado >= (vbotao_1 - 10) && dado <= (vbotao_1 + 10)){
    return BOTAO_1;
  } else if(dado >= (vbotao_2 - 10) && dado <= (vbotao_2 + 10)){
    return BOTAO_2;
  } else {
    return NAO_PRESSIONADO;
  }

}
