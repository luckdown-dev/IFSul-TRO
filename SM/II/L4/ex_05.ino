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

ShiftRegister74HC595 leds(1, DATA_PIN, CLOCK_PIN, LATCH_PIN);

int posicaoLed = 0;
int sentido = 1; // 1 for clockwise, -1 for counterclockwise
unsigned long tempoPassado = 0;
const long intervalo = 150; // milliseconds

void setup() {
  sr.setAllLow();
  pinMode(BOTOES_PIN, INPUT);
}

void loop() {
  unsigned long tempoAtual = millis();
  int estadoBotao = leBotao();
  
  if (estadoBotao == BOTAO_0) {
    sentido = 1;
  } else if (estadoBotao == BOTAO_1) {
    sentido = -1;
  }
  
  if (tempoAtual - tempoPassado >= intervalo) {
    tempoPassado = tempoAtual;
    leds.setAllLow();
    leds.set(posicaoLed, 1);
    posicaoLed = posicaoLed + sentido;
    if (posicaoLed < 0) {
      posicaoLed = 7;
    } else if (posicaoLed > 7) {
      posicaoLed = 0;
    }
  }
}

int leBotao() {
  int dado = analogRead(BOTOES_PIN);

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
