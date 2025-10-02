int led[] = {11, 10, 9}; //pino dos leds, array com 3 espaços definidos
int pinpot = A0; //pino do potenciômetro
int pot = 0; //guardar valor do potenciômetro
int red = 0, green = 0, blue = 0; //guardar valor das 3 cores
// int maxred = 255, maxgreen = 255, maxblue = 255; //calibração
void setup() {
  Serial.begin(9600); //tempo de comunicação consistente
  for (int i = 0; i < 3; i++) { //pega todos os 3 espaços do array (0-2)
    pinMode(led[i],OUTPUT); //define os 3 espaços do array como pinos OUTPUT
  }
}
void loop() {
  pot = analogRead(pinpot); //variável será o valor da leitura no pino do potenciômetro
  if(pot < 1) { //nada
    red = 0;
    green = 0;
    blue = 0;
  }
  else if(pot < 128) { //nada > só vermelho
    red = map(pot, 0, 128, 0, 255);
    green = 0;
    blue = 0;
  }
  else if(pot < 256) { //só vermelho > verde
    red = 255;
    green = map(pot, 128, 256, 0, 255);
    blue = 0;
  }
  else if(pot < 384) { //verde > só verde
    red = map(pot, 256, 384, 255, 0);
    green = 255;
    blue = 0;
  }
  else if(pot < 512) { //só verde > azul
    red = 0;
    green = 255;
    blue = map(pot, 384, 512, 0, 255);
  }
  else if(pot < 640) { //azul > só azul
    red = 0;
    green = map(pot, 512, 640, 255, 0);
    blue = 255;
  }
  else if(pot < 768) { //só azul > vermelho
    red = map(pot, 640, 768, 0, 255);
    green = 0;
    blue = 255;
  }
  else if(pot < 896) { //vermelho > só vermelho
    red = 255;
    green = 0;
    blue = map(pot, 768, 896, 255, 0);
  }
  else (pot <= 1023) { //só vermelho > branco
    red = 255;
    green = map(pot, 896, 1023, 0, 255);
    blue = map(pot, 896, 1023, 0, 255);
  }
  analogWrite(led[0],red); //associa o primeiro led com os valores analogico do vermelho
  analogWrite(led[1],green); //associa o segundo led com os valores analogico do verde
  analogWrite(led[2],blue); //associa o terceiro led com os valores analogico do azul
  //caso precisar de calibração
  /*analogWrite(led[0],red * maxred / 255);
  analogWrite(led[1],green * maxgreen / 255);
  analogWrite(led[2],blue * maxblue / 255);*/
  Serial.print("leitura: ");
  Serial.print(pot);
  Serial.print(" R:");
  Serial.print(red);
  Serial.print(" G:");
  Serial.print(green);
  Serial.print(" B:");
  Serial.println(blue);
  delay(10);
}