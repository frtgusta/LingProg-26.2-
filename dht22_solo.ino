// ============================================================
// Projeto: Leitura do Sensor DHT22
// Descrição: Lê temperatura (ºC) e umidade (%) e exibe no Monitor Serial
// Hardware: Arduino Uno + Sensor DHT22 (Pino Data no D7)
// Requisitos: Biblioteca "DHT sensor library" (Adafruit)
// ============================================================

#include <DHT.h> // Inclui a biblioteca de controle do sensor

#define DHTPIN 7       // Pino digital conectado ao DATA do DHT22
#define DHTTYPE DHT22  // Define o modelo do sensor (DHT22)

// Inicializa o objeto do sensor informando o pino e o modelo
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600); // Inicia a comunicação serial a 9600 bps
  dht.begin();        // Inicializa o sensor DHT22
  Serial.println("--- Inicio da Leitura do Sensor DHT22 ---");
}

void loop() {
  // Leitura da umidade relativa do ar (%)
  float umidade = dht.readHumidity();
  
  // Leitura da temperatura em graus Celsius (°C)
  float temperatura = dht.readTemperature();

  // Verifica se ocorreu alguma falha na leitura dos dados
  if (isnan(umidade) || isnan(temperatura)) {
    Serial.println("Erro ao ler os dados do sensor DHT22!");
    return; // Encerra o ciclo atual e tenta novamente no próximo
  }

  // Exibe os dados formatados no Monitor Serial
  Serial.print("Umidade: ");
  Serial.print(umidade);
  Serial.print(" % | Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" *C");

  delay(2000); // Intervalo recomendado pelo fabricante (2 segundos)
}