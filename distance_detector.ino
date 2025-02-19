#define LED_RED 10
#define LED_YELLOW 9
#define LED_GREEN 8

int cm = 0;

long ReadDistance(int TriggerPin, int EchoPin) {
  pinMode(TriggerPin, OUTPUT);
  digitalWrite(TriggerPin, LOW);
  delayMicroseconds(2);

  digitalWrite(TriggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(TriggerPin, LOW);

  pinMode(EchoPin, INPUT);
  return pulseIn(EchoPin, HIGH);
}

void setup() {
  Serial.begin(9600);

  pinMode(LED_RED, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);

  digitalWrite(LED_RED, LOW);
  digitalWrite(LED_YELLOW, LOW);
  digitalWrite(LED_GREEN, LOW);
}

void loop() {
  cm = 0.01723 * ReadDistance(2, 3);

  Serial.print(cm);
  Serial.println(" cm");

  if (cm <= 0) {
    // Valor inválido ou sem leitura
    digitalWrite(LED_RED
  , LOW);
    digitalWrite(LED_YELLOW, LOW);
    digitalWrite(LED_GREEN, LOW);
    return;
  }

  if (cm <= 10) {
    digitalWrite(LED_RED, LOW);
    digitalWrite(LED_YELLOW, LOW);
    digitalWrite(LED_GREEN, HIGH);
  } else if (cm > 20 && cm <= 40) {
    digitalWrite(LED_RED, LOW);
    digitalWrite(LED_YELLOW, HIGH);
    digitalWrite(LED_GREEN, LOW);
  } else if (cm > 40) {
    digitalWrite(LED_RED, HIGH);
    digitalWrite(LED_YELLOW, LOW);
    digitalWrite(LED_GREEN, LOW);
  }

  delay(1000);
}
