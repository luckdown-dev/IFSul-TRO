#include <ShiftRegister74HC595.h>

#define DATA_PIN 2
#define LATCH_PIN 3
#define CLOCK_PIN 4
#define BOTOES_PIN A3

#define BOTAO_0  0
#define BOTAO_1  1
#define BOTAO_2  2
#define NAO_PRESSIONADO -1

int vbotao_0 = 680, vbotao_1=829, vbotao_2=927;

const long intervalo = 100;
unsigned long tempoPassado = 0;

const long intervaloPisca = 500;
unsigned long tempoPassadoPisca = 0;

unsigned long ultimoRepique = 0;
unsigned long repiqueDelay = 50; // delay do repique

int posicao = 0, sentido, opcao = 0;
int estado = 0;

ShiftRegister74HC595 leds(1, DATA_PIN, CLOCK_PIN, LATCH_PIN);

void setup(){

}

void loop(){
  unsigned long tempoAtual = millis();
  int botaoPressionado = leBotaoRepique();

  if(botaoPressionado == BOTAO_0){
    opcao = 1;

  } else if(botaoPressionado == BOTAO_1){
    opcao = 2;
    sentido = 1;
    
  } else if(botaoPressionado == BOTAO_2){
    opcao = 3;
    sentido = -1;
    
  }

  if(tempoAtual - tempoPassado >= intervalo){
    tempoPassado = tempoAtual;
    if(opcao == 1){
      unsigned long tempoPisca = millis();

      if(tempoPisca - tempoPassadoPisca >= intervaloPisca){
        for(int c=0; c<=7; c++){
          leds.set(c, estado);
        }
        estado = !estado;
        tempoPassadoPisca = tempoPisca;
      }

    }
    if (opcao == 2){
        leds.setAllLow();
        leds.set(posicao, 1);

        posicao += sentido;

        if(posicao < 0){
          posicao = 7;

        } else if(posicao > 7){
          posicao = 0;

        }

    } else if (opcao == 3){
        leds.setAllHigh();
        leds.set(posicao, 0);

        posicao += sentido;

        if(posicao < 0){
          posicao = 7;

        } else if(posicao > 7){
          posicao = 0;

        }
    }
  }
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
