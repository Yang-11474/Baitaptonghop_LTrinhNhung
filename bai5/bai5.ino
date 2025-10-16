#include <LiquidCrystal_I2C.h>
// LiquidCrystal lcd(12,11,5,4,3,2);
LiquidCrystal_I2C lcd(0x27, 16, 2);
int btn=10;
int led=9;
bool btnState=HIGH;
int pre=LOW;
void setup() {
  // put your setup code here, to run once:
  pinMode(btn,INPUT);
  pinMode(led,OUTPUT);
 
}
void loop() {
  // put your main code here, to run repeatedly:
 int current=digitalRead(btn);
 if(pre==LOW &&current==HIGH){
  btnState=!btnState;
  if(btnState==HIGH)
  {
    digitalWrite(led,HIGH);
     lcd.noBacklight();
    delay(200);
  }
  else
  {
    digitalWrite(led,LOW);
    lcd.backlight();
    delay(200);
  }

 }

 pre=current;
}
