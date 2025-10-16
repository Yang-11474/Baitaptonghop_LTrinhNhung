#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);

int sensor = A0;
int led = 2;
int btnC = 7;
int btnF = 8;

bool C = true;
String nhietDo = "";
long long prevMillis = 0;

void setup() {
  // put your setup code here, to run once:
  lcd.init();
  lcd.backlight();
  pinMode(led, OUTPUT);
  pinMode(btnC, INPUT);
  pinMode(btnF, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly
  long long curMillis = millis();
  int curBtnC = digitalRead(btnC);
  int curBtnF = digitalRead(btnF);

  int readingTotal = 0;
  for (int i = 0; i < 100; i++) {
    readingTotal += analogRead(sensor);
  }
  float reading = readingTotal / 100.0;
  float voltage = reading * 5.0 / 1023.0;
  float tempC = voltage * 100;
  float tempF = (tempC * 1.8) + 32;

  if (curBtnC == HIGH) {
    C = true;
  }
  if (curBtnF == HIGH) {
    C = false;
  }

  if (tempC < 15) {
    nhietDo = "Thap";
    digitalWrite(led, LOW);
  } else if (tempC > 40) {
    nhietDo = "Cao";
    if (curMillis - prevMillis <= 500) {
      digitalWrite(led, HIGH);
    } else if (curMillis - prevMillis <= 1000) {
      digitalWrite(led, LOW);
    } else {
      prevMillis = curMillis;
    }
  } else {
    nhietDo = "Binh thuong";
    digitalWrite(led, HIGH);
  }

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(nhietDo);
  lcd.setCursor(0, 1);
  if (C) {
    lcd.print(tempC);
    lcd.print("C");
  } else {
    lcd.print(tempF);
    lcd.print("F");
  }
  delay(1000);
}
