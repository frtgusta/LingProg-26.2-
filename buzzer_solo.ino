// ============================================================
// Projeto: Controle de Buzzer Solo
// Descrição: Faz o buzzer emitir um sinal sonoro piscante (beep)
// Hardware: Arduino Uno + Buzzer conectado ao pino D8
// ============================================================

const int buzzerPin = 8; // Pino digital conectado ao Buzzer

void setup() {
  // Configura a porta digital do buzzer como SAÍDA de energia
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // tone(pino, frequencia): Toca uma nota na frequência de 1000 Hz
  tone(buzzerPin, 1000);
  delay(500); // Aguarda 500 milissegundos (0,5 segundos) com o som ligado

  // noTone(pino): Interrompe a emissão de som do buzzer
  noTone(buzzerPin);
  delay(500); // Aguarda 500 milissegundos em silêncio
}