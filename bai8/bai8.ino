// #include <LiquidCrystal_I2C.h>
#include <LiquidCrystal.h>
// LiquidCrystal_I2C lcd(0x27, 16, 2);
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int btnE = 10;
int btnO = 9;
int btnF = 8;
int btnS = 7;

byte EE[8] = {
  B00100,
  B01010,
  B00000,
  B01110,
  B01100,
  B01000,
  B00110,
  B00000
};

byte OO[8] = {
 B00100,
  B01010,
  B00000,
  B01110,
  B01010,
  B01010,
  B01110,
  B00000
};

byte EF[8] = {
  B01000,
  B00100,
  B01110,
  B01010,
  B01100,
  B01000,
  B01110,
  B00000
};

byte ES[8] = {
  B00010,
  B00100,
  B01110,
  B01010,
  B01100,
  B01000,
  B01110,
  B00000
};

byte OF[8] = {
  B01000,
  B00100,
  B01110,
  B01010,
  B01010,
  B01010,
  B01110,
  B00000
};

byte OS[8] = {
  B00010,
  B00100,
  B01110,
  B01010,
  B01010,
  B01010,
  B01110,
  B00000
};

int preChar = 0;
int curChar;
int cursorX = 0;
int cursorY = 0;

int preBtnE = LOW;
int preBtnO = LOW;
int preBtnF = LOW;
int preBtnS = LOW;

void setup() {
  // put your setup code here, to run once:
  // lcd.init();
  // lcd.backlight();
  lcd.clear();
  pinMode(btnE, INPUT);
  pinMode(btnO, INPUT);
  pinMode(btnF, INPUT);
  pinMode(btnS, INPUT);
  lcd.createChar(0, EE);
  lcd.createChar(1, OO);
  lcd.createChar(2, EF);
  lcd.createChar(3, ES);
  lcd.createChar(4, OF);
  lcd.createChar(5, OS);
  lcd.setCursor(cursorX, cursorY);
}

void loop() {
  // put your main code here, to run repeatedly:
  int curBtnE = digitalRead(btnE);
  int curBtnO = digitalRead(btnO);
  int curBtnF = digitalRead(btnF);
  int curBtnS = digitalRead(btnS);

  curChar = 0;
  
  if (curBtnE == HIGH && preBtnE == LOW) {
    if (preChar == 1) curChar = 5;//EE
    else curChar = 1;//E
  }
  if (curBtnO == HIGH && preBtnO == LOW) {
<<<<<<< HEAD
    if(preChar==2) curChar=6;//OO
=======
    if(preChar==1) curChar=6;//OO
>>>>>>> fb9b852947ed04b0385df489a837fe5d6deb072e
    else curChar = 2;//O
  }
  if (curBtnF == HIGH && preBtnF == LOW) {
    if (preChar == 1) curChar = 7;//EF
    else if (preChar == 2) curChar = 9;//OF
    else curChar=3;
  }
  if (curBtnS == HIGH && preBtnS == LOW) {
    if (preChar == 1) curChar = 8;//ES
    else if (preChar == 2) curChar = 10;//OS
    else curChar=4;
  }

  switch (curChar) {
    case 1: {
      lcd.setCursor(cursorX, cursorY);
      lcd.print("E");
      cursorX++;
      if (cursorX > 15) {
        cursorX = 0;
        cursorY++;
        if (cursorY > 1) cursorY = 0;
      }
      preChar = curChar;
      break;
    }
    case 2: {
      lcd.setCursor(cursorX, cursorY);
      lcd.print("O");
      cursorX++;
      if (cursorX > 15) {
        cursorX = 0;
        cursorY++;
        if (cursorY > 1) cursorY = 0;
      }
      preChar = curChar;
      break;
    }
    case 3: {
      lcd.setCursor(cursorX, cursorY);
      lcd.print("F");
      cursorX++;
      if (cursorX > 15) {
        cursorX = 0;
        cursorY++;
        if (cursorY > 1) cursorY = 0;
      }
      preChar = curChar;
      break;
    }
    case 4: {
      lcd.setCursor(cursorX, cursorY);
      lcd.print("S");
      cursorX++;
      if (cursorX > 15) {
        cursorX = 0;
        cursorY++;
        if (cursorY > 1) cursorY = 0;
      }
      preChar = curChar;
      break;
    }
    //EE
    case 5: {
      if (cursorX == 0) {
        if (cursorY == 0) {
          lcd.setCursor(15, 1);
        }
        else lcd.setCursor(15, 0);
      }
      else {
        lcd.setCursor(cursorX - 1, cursorY);
      }
      lcd.print(char(0));
      preChar = curChar;
      break;
    }
    //OO
    case 6: {
      if (cursorX == 0) {
        if (cursorY == 0) {
          lcd.setCursor(15, 1);
        }
        else lcd.setCursor(15, 0);
      }
      else {
        lcd.setCursor(cursorX - 1, cursorY);
      }
      lcd.print(char(1));
      preChar = curChar;
      break;
    }
    //EF
    case 7: {
      if (cursorX == 0) {
        if (cursorY == 0) {
          lcd.setCursor(15, 1);
        }
        else lcd.setCursor(15, 0);
      }
      else {
        lcd.setCursor(cursorX - 1, cursorY);
      }
      lcd.print(char(2));
      preChar = curChar;
      break;
    }
    //ES
    case 8: {
      if (cursorX == 0) {
        if (cursorY == 0) {
          lcd.setCursor(15, 1);
        }
        else lcd.setCursor(15, 0);
      }
      else {
        lcd.setCursor(cursorX - 1, cursorY);
      }
      lcd.print(char(3));
      preChar = curChar;
      break;
    }
    //OF
    case 9: {
      if (cursorX == 0) {
        if (cursorY == 0) {
          lcd.setCursor(15, 1);
        }
        else lcd.setCursor(15, 0);
      }
      else {
        lcd.setCursor(cursorX - 1, cursorY);
      }
      lcd.print(char(4));
      preChar = curChar;
      break;
    }
    //OS
     case 10: {
      if (cursorX == 0) {
        if (cursorY == 0) {
          lcd.setCursor(15, 1);
        }
        else lcd.setCursor(15, 0);
      }
      else {
        lcd.setCursor(cursorX - 1, cursorY);
      }
      lcd.print(char(5));
      preChar = curChar;
      break;
    }
    default: {
      
    }
  }
  
  preBtnE = curBtnE;
  preBtnO = curBtnO;
  preBtnF = curBtnF;
  preBtnS = curBtnS;

  delay(30);
}
