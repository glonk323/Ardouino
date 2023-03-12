#define IRr 2
#define IRl 3
#define RightM1 4
#define RightM2 5
#define LeftM1 6
#define LeftM2 7
void setup() {
PinMode(RightM1, OUTPUT);
PinMode(RightM2, OUTPUT);
PinMode(LeftM1, OUTPUT);
PinMode(LeftM2, OUTPUT);
}

void loop() {
int Rv = digitalRead(IRr);
int Lv = digitalRead(IRl);
  if(Rv == 0 & Lv == 0){ 
    digitalWrite(RightM1, HIGH);
    digitalWrite(LeftM1, HIGH);
    digitalWrite(RightM2, LOW);
    digitalWrite(LeftM2, LOW);
  }else if(Rv == 1 & Lv == 0){ 
    digitalWrite(RightM1, LOW);
    digitalWrite(LeftM1, HIGH);
    digitalWrite(RightM2, LOW);
    digitalWrite(LeftM2, LOW);
  }else if(Rv == 0 & Lv == 1){ 
    digitalWrite(RightM1, HIGH);
    digitalWrite(LeftM1, LOW);
    digitalWrite(RightM2, LOW);
    digitalWrite(LeftM2, LOW);
  }else if(Rv == 1 & Lv == 1){ 
    digitalWrite(RightM1, LOW);
    digitalWrite(LeftM1, LOW);
    digitalWrite(RightM2, LOW);
    digitalWrite(LeftM2, LOW);
  }
  }
