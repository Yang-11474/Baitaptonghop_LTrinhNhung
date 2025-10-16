int led = 10;
int btnTang = 3;
int btnGiam = 2;
int delayTime = 500;
int delayDelta = 100;
int delayMin = 100;
int delayMax = 5000;
unsigned long long preMillis = 0;
int preBtnTang = LOW;
int preBtnGiam = LOW;

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  pinMode(btnTang, INPUT);
  pinMode(btnGiam, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long long curMillis = millis();
  int curBtnTang = digitalRead(btnTang);
  int curBtnGiam = digitalRead(btnGiam);

  if(curBtnTang == HIGH && preBtnTang == LOW) {
    delayTime -= delayDelta;
    if (delayTime < delayMin) delayTime = delayMin;
  }
  if (curBtnGiam == HIGH && preBtnGiam == LOW) {
    delayTime += delayDelta;
    if (delayTime > delayMax) delayTime = delayMax;
  }

  if (curMillis - preMillis <= delayTime) {
    digitalWrite(led, HIGH);
  } else if (curMillis - preMillis <= delayTime * 2) {
    digitalWrite(led, LOW);
  } else {
    preMillis = curMillis;
  }

  preBtnTang = curBtnTang;
  preBtnGiam = curBtnGiam;
}
