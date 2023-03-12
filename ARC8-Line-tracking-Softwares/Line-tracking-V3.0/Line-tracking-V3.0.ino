int MiddleS = 2 ;
int RightS = 3; 
int LeftS = 4;
int RightMf = 5;
int RightMb = 6;
int LeftMf = 7;
int LeftMb = 8;
int MiddleV = LOW;
int RightV = LOW;
int LeftV = LOW;
void setup(){
pinMode(MiddleS,INPUT);
pinMode(RightS,INPUT);
pinMode(LeftS,INPUT);
pinMode(RightMf, OUTPUT);
pinMode(RightMb, OUTPUT);
pinMode(LeftMf, OUTPUT);
pinMode(LeftMb, OUTPUT);
} 

void ReadSensors(){
int MiddleV = digitalRead(MiddleS);
int RightV = digitalRead(RightS);
int LeftV = digitalRead(LeftS);
}

void Refresh(){
digitalWrite(RightMf, LOW);
digitalWrite(RightMb, LOW);
digitalWrite(LeftMf, LOW);
digitalWrite(LeftMb, LOW);
}

void Straight(){
  Refresh();
digitalWrite(RightMf, HIGH);
digitalWrite(LeftMf, HIGH);
}

void Right(){
  Refresh();
digitalWrite(LeftMf, HIGH);
}

void Left(){
  Refresh();
digitalWrite(RightMf, HIGH);
}

void Stop(){
  Refresh();
}

void Track(){
if((MiddleV == 1) & (RightV == 0 & LeftV == 0)){
  Straight();
}else if((RightV == 1) & (MiddleV == 0 & LeftV == 0) || ((MiddleV == 1 & RightV == 1) & (LeftV == 0))){
  Right();
}else if((LeftV == 1) & (RightV == 0 & MiddleV == 0) || ((MiddleV == 1 & LeftV == 1) & (RightV == 0))){
  Left();
}else if(RightV == 0 & MiddleV == 0 & LeftV == 0){
  Straight();
}else if(RightV == 1 & MiddleV == 1 & LeftV == 1){
  Stop();
      }
    }
  

void loop(){
Track();
}