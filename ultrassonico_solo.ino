// ============================================================
// Projeto: Sensor Ultrassônico HC-SR04 Solo
// Descrição: Mede a distância de objetos em centímetros
// Hardware: Arduino Uno + HC-SR04 (Trig no D9, Echo no D10)
// ============================================================

const int trigPin = 9;  // Pino Trig (Emissor do som)
const int echoPin = 10; // Pino Echo (Receptor do som)

long duration; // Armazena o tempo do pulso (microsegundos)
int distance;  // Armazena a distância calculada (centímetros)

void setup() {
  Serial.begin(9600);       // Inicia a comunicação serial
  pinMode(trigPin, OUTPUT); // Trig atua como SAÍDA (envia o sinal)
  pinMode(echoPin, INPUT);  // Echo atua como ENTRADA (escuta o retorno)
}

void loop() {
  // Limpa o pino Trig garantindo nível baixo
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Envia um pulso sonoro de 10 microsegundos
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // pulseIn: Mede quanto tempo (em us) o pino Echo ficou em nível ALTO
  duration = pulseIn(echoPin, HIGH);

  // Calcula a distância em cm (Tempo * Velocidade do Som / 2)
  distance = duration * 0.034 / 2;

  // Imprime o resultado no Monitor Serial
  Serial.print("Distancia: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(500); // Aguarda meio segundo entre as medições
}