// ============================================================
// Projeto: Alarme de Proximidade (Ultrassônico + Buzzer)
// Descrição: Aciona o buzzer se um objeto estiver a menos de 15 cm
// Hardware: Arduino Uno + HC-SR04 (D9/D10) + Buzzer (D8)
// ============================================================

const int trigPin = 9;   // Pino Trig do ultrassônico
const int echoPin = 10;  // Pino Echo do ultrassônico
const int buzzerPin = 8; // Pino do Buzzer

long duration;
int distance;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // Emite o pulso do sensor ultrassônico
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Recebe o tempo de retorno e calcula a distância em cm
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  // Exibe a distância lida no Monitor Serial
  Serial.print("Distancia: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Lógica do alarme: se houver objeto a menos de 15 cm
  if (distance > 0 && distance < 15) {
    tone(buzzerPin, 1000); // Liga o buzzer na frequência de 1000 Hz
  } else {
    noTone(buzzerPin);     // Desliga o buzzer quando longe ou fora de alcance
  }

  delay(200); // Intervalo mais rápido para resposta imediata do alarme
}