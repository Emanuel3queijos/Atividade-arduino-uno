
#define pinoBotao 2
#define pinoLed 5

void setup()
{
  pinMode(pinoBotao, INPUT_PULLUP);
  pinMode( pinoLed, OUTPUT);
}

void loop()
{

  int botao = digitalRead(pinoBotao);
  if(botao == LOW){
  
   digitalWrite( pinoLed, LOW );
  } else {
  digitalWrite( pinoLed, HIGH );
  
  }
}
