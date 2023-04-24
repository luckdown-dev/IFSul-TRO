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
unsigned long ultimoRepique = 0;
unsigned long repiqueDelay = 50; // delay do debounce

void setup() {
  pinMode(botoes, INPUT);
  pinMode(vermelho, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(azul, OUTPUT);
}

void loop() {
  int botao = leBotaoRepique(); // chamada da função de leitura com debounce
  if(botao == BOTAO_2){
    digitalWrite(vermelho, !digitalRead(vermelho));
    delay(300);
  }

  if(botao == BOTAO_1){
    digitalWrite(verde, !digitalRead(verde));
    delay(300);
  }

  if(botao == BOTAO_0){
    digitalWrite(azul, !digitalRead(azul));
    delay(300);
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
