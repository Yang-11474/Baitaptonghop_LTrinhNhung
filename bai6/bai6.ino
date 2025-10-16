#include<LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
int btnTrai=10;
int btnPhai=9;
int btnTat=6;
int pre=LOW;
int pre1=LOW;
int pre2=LOW;
<<<<<<< HEAD
int column=0;
bool trangthai=true;
=======
int column=6;
>>>>>>> fb9b852947ed04b0385df489a837fe5d6deb072e
void setup() {
  // put your setup code here, to run once:
  pinMode(btnTrai,INPUT);
  pinMode(btnPhai,INPUT);
  pinMode(btnTat,INPUT);
  lcd.begin(16,2);
  lcd.setCursor(column,0);
  lcd.print("Hello");
}

void loop() {
  // put your main code here, to run repeatedly:
<<<<<<< HEAD
  int current=digitalRead(btnTrai);
  int current1=digitalRead(btnPhai);
  int current2=digitalRead(btnTat);
  if(pre==LOW &&current==HIGH)
  {
    lcd.clear();
    column-=2;
    if(column<=0) column=0;
    lcd.setCursor(column, 0);
    lcd.print("Hello");
    pre=current;
  }
  pre=current;

  if(pre1==LOW&& current1==HIGH){
    lcd.clear();
    column+=2;
    if(column>=10) column=10;//tru chu hello
    lcd.setCursor(column, 0);
    lcd.print("Hello");
    pre1=current1;
  }
  pre1=current1;

  if(pre2==LOW &&current2==HIGH)
  {
    lcd.noDisplay();
  }
  pre2=current2;



  // if(pre==LOW &&current1==HIGH)
  // {
  //   lcd.clear();
  //   lcd.display();
  //   column-=2;
  //   lcd.setCursor(column,0);
    
  //   lcd.print("Hello");
  //   delay(200);
  // }
  // pre=current1;
  // if(pre1==LOW &&current2==HIGH)
  // {
  //   lcd.clear();
  //   lcd.display();
  //   column+=2;
  //   lcd.setCursor(column,0);
  //   lcd.print("Hello");
  //   delay(200);
  // }
  // pre1=current2;
  // if(pre2==LOW &&current3==HIGH)
  // {
  //   lcd.noDisplay();
  // }
  // pre2=current3;
=======
  int current1=digitalRead(btnTrai);
  int current2=digitalRead(btnPhai);
  int current3=digitalRead(btnTat);
  if(pre==LOW &&current1==HIGH)
  {
    lcd.clear();
    lcd.display();
    column-=2;
    lcd.setCursor(column,0);
    
    lcd.print("Hello");
    delay(200);
  }
  pre=current1;
  if(pre1==LOW &&current2==HIGH)
  {
    lcd.clear();
    lcd.display();
    column+=2;
    lcd.setCursor(column,0);
    lcd.print("Hello");
    delay(200);
  }
  pre1=current2;
  if(pre2==LOW &&current3==HIGH)
  {
    lcd.noDisplay();
  }
  pre2=current3;
>>>>>>> fb9b852947ed04b0385df489a837fe5d6deb072e

 
}
