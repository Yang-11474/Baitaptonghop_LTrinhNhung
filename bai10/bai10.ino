#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4) ;
int doo=10;
int xanh=9;
int vang=8;
int btn=6;
int pre=LOW;
int sensorPin = A0;
bool doC = true;
void setup() {
  // put your setup code here, to run once:
pinMode(doo,OUTPUT);
pinMode(xanh,OUTPUT);
pinMode(vang,OUTPUT);
pinMode(btn,INPUT);
  lcd.init();
  lcd.backlight();
}

void loop() {
  // put your main code here, to run repeatedly:
  int temp = 0;
    for ( int i = 0; i < 100; i++ ) {
      int tmp = analogRead(sensorPin);
      if (tmp == 0) {
        i--;
        continue;
      }
      temp += tmp;
    }
  int reading = temp / 100; 
  float voltage = reading * 5.0 / 1023.0;
  float tempC = voltage * 100.0; 
  float tempF = (tempC * 1.8) + 32;
  
  int current = digitalRead(btn);
  if(pre==LOW &&current==HIGH){
    doC = !doC;
  }
  
  if(tempC>=15 && tempC<=30) {
    digitalWrite(vang,HIGH);
    digitalWrite(doo, LOW);
    digitalWrite(xanh, LOW);
  }
  else if(tempC>30){
    digitalWrite(doo,HIGH);
    digitalWrite(vang, LOW);
    digitalWrite(xanh, LOW);
  }
  else {
    digitalWrite(xanh, HIGH);
    digitalWrite(doo, LOW);
    digitalWrite(vang, LOW);  
  }
  
  lcd.clear();
  if (doC) {
    lcd.print(tempC);
    lcd.print("C");
  } else {
    lcd.print(tempF);
    lcd.print("F");
  }
  
  pre=current;
  delay(500);
}
