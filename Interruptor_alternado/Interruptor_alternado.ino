#define pinoBotao 2
#define pinoLed 5

enum EstadoLED { ACESO, PISCANDO_RAPIDO, PARADO };
EstadoLED estadoAtual = ACESO;

void setup() {
  pinMode(pinoBotao, INPUT_PULLUP);
  pinMode(pinoLed, OUTPUT);
  digitalWrite(pinoLed, LOW);
}

void loop() {
  static int lastButtonState = HIGH; 
  int buttonState = digitalRead(pinoBotao);

  if (lastButtonState == HIGH && buttonState == LOW) {
    estadoAtual = static_cast<EstadoLED>((estadoAtual + 1) % 3);
    delay(200); 
  }

  lastButtonState = buttonState;

  switch (estadoAtual) {
    case ACESO:
      digitalWrite(pinoLed, HIGH); 
      break;
    case PISCANDO_RAPIDO:
      digitalWrite(pinoLed, HIGH);
      delay(200);
      digitalWrite(pinoLed, LOW);
      delay(200);
      break;
  }
}
