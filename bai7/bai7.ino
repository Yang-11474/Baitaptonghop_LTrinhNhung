#include<LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);

byte AW[] = {
  B10001,
  B01110,
  B00000,
  B00100,
  B01010,
  B10101,
  B10001,
  B00000
};

byte AA[] = {
  B00100,
  B01010,
  B00000,
  B00100,
  B01010,
  B10101,
  B10001,
  B00000
};
byte DD[] = {
  B11100,
  B10010,
  B10001,
  B10001,
  B10001,
  B10010,
  B11100,
  B00000
};
byte EE[] = {
  B00100,
  B01010,
  B00000,
  B01110,
  B01010,
  B01000,
  B01110,
  B00000
};
byte OO[] = {
  B00100,
  B01010,
  B00000,
  B01110,
  B01010,
  B01010,
  B01110,
  B00000
};
byte OW[] = {
  B00100,
  B01010,
  B00010,
  B01110,
  B01010,
  B01010,
  B01110,
  B00000
};
byte UW[] = {
  B00111,
  B00101,
  B00101,
  B10001,
  B10001,
  B10001,
  B11111,
  B00000
};

void setup() {
  lcd.begin(16,2);
  // put your setup code here, to run once:
  lcd.createChar(0, AW);
  lcd.createChar(1, AA);
  lcd.createChar(2, DD);
  lcd.createChar(3, EE);
  lcd.createChar(4, OO);
  lcd.createChar(5, OW);
  lcd.createChar(6, OW);
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.write(byte(0));
  lcd.write(byte(1));
  lcd.write(byte(2));
  lcd.write(byte(3));
  lcd.write(byte(4));
  lcd.write(byte(5));
  lcd.write(byte(6));
  // put your main code here, to run repeatedly:
  delay(1000);

}

void loop() {
  
}
