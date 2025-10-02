int led[] = {11, 10, 9}; //led pins, array com 3 defined spaces
int pinpot = A0; //potentiometer pin
int pot = 0; //store potentiometer value
int red = 0, green = 0, blue = 0; //store value from the 3 colors(rgb)
// int maxred = 255, maxgreen = 255, maxblue = 255; //calibration
void setup() {
  Serial.begin(9600); //consistent comunnication time
  for (int i = 0; i < 3; i++) { //picks all 3 spaces from the array(0-2)
    pinMode(led[i],OUTPUT); //define the 3 spaces from the array as OUTPUT
  }
}
void loop() {
  pot = analogRead(pinpot); //variable will be the value of the reading from the potentiometer
  if(pot < 1) { //nothing
    red = 0;
    green = 0;
    blue = 0;
  }
  else if(pot < 128) { //nothing > only red
    red = map(pot, 0, 128, 0, 255);
    green = 0;
    blue = 0;
  }
  else if(pot < 256) { //only red > green
    red = 255;
    green = map(pot, 128, 256, 0, 255);
    blue = 0;
  }
  else if(pot < 384) { //green > only green
    red = map(pot, 256, 384, 255, 0);
    green = 255;
    blue = 0;
  }
  else if(pot < 512) { //only green > blue
    red = 0;
    green = 255;
    blue = map(pot, 384, 512, 0, 255);
  }
  else if(pot < 640) { //blue > only blue
    red = 0;
    green = map(pot, 512, 640, 255, 0);
    blue = 255;
  }
  else if(pot < 768) { //only blue > red
    red = map(pot, 640, 768, 0, 255);
    green = 0;
    blue = 255;
  }
  else if(pot < 896) { //red > only red
    red = 255;
    green = 0;
    blue = map(pot, 768, 896, 255, 0);
  }
  else (pot <= 1023) { //only red > white
    red = 255;
    green = map(pot, 896, 1023, 0, 255);
    blue = map(pot, 896, 1023, 0, 255);
  }
  analogWrite(led[0],red); //associates the first led with analog values from red
  analogWrite(led[1],green); //associates the second led with analog values from green
  analogWrite(led[2],blue); //associates the third led with analog values from blue
  //in case you need calibration(check if the resistor's ohms are the same)
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