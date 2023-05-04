#include <ShiftRegister74HC595.h>
#include <ShiftDisplay.h>

#define DATA_PIN 2
#define LATCH_PIN 3
#define CLOCK_PIN 4
#define BOTOES_PIN A3

#define BOTAO_0  0
#define BOTAO_1  1
#define BOTAO_2  2
#define NAO_PRESSIONADO -1

int vbotao_0 = 680, vbotao_1=829, vbotao_2=927;

long intervalo = 500;
unsigned long tempoPassado = 0;

long botaoDelay = 250;
unsigned long tempoAtualBotao;
unsigned long tempoPassadoBotao = 0;

unsigned long ultimoRepique = 0;
unsigned long repiqueDelay = 50; // delay do repique

int posicao = 0;

ShiftRegister74HC595 leds(1, DATA_PIN, CLOCK_PIN, LATCH_PIN);
ShiftDisplay display7s(COMMON_CATHODE, 4);

void setup(){

}

void loop(){
  unsigned long tempoAtual = millis();
  int botaoPressionado = leBotao();

  if(botaoPressionado != NAO_PRESSIONADO){
    tempoAtualBotao = millis();

    if(tempoAtualBotao - tempoPassadoBotao >= botaoDelay){
      tempoPassadoBotao = tempoAtualBotao;

      if(botaoPressionado == BOTAO_0){
        intervalo += 100;

      } else if(botaoPressionado == BOTAO_1){
        if(intervalo > 100){
          intervalo -= 100;
        }  
      }
    }
  }

  if(tempoAtual - tempoPassado >= intervalo){
    tempoPassado = tempoAtual;

    leds.setAllLow();
    leds.set(posicao, 1);
    posicao += 1;
  }

  if(posicao > 7){
    posicao = 0;
  }

  display7s.set(intervalo);
  display7s.show();

}
// FUNÇÕES

int leBotao(){
  int dado = analogRead(BOTOES_PIN);

  if (dado>= (vbotao_0 - 10) && dado <= (vbotao_0 + 10)){
    return BOTAO_0;

  } else if (dado>= (vbotao_1 - 10) && dado <= (vbotao_1 + 10)){
    return BOTAO_1;
    
  } else if (dado>= (vbotao_2 - 10) && dado <= (vbotao_2 + 10)){
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
