int sensRR = A0;     //Sets sensRR's pin to Analog 0
int sensMidR = A1;  //Sets sensMidR's pin to Analog 1
int sensMidL = A2; //Sets sensMidL's pin to Analog 2
int sensLL = A3;  //Sets sensLL's pin to Analog 3
#define RightMotor1 6   //defines RightMotor1 (FORWARD PIN) that it's 6
#define LeftMotor1 7   //defines LeftMotor1 (FORWARD PIN) that it's 7
#define RightMotor2 8 //defines RightMotor2 (BACKWARD PIN) that it's 8
#define LeftMotor2 9 //defines LeftMotor2 (BACKWARD PIN) that it's 9
void setup() {
 pinMode(RightMotor1,OUTPUT);    //Sets RightMotor1 to OUTPUT
 pinMode(LeftMotor1,OUTPUT);    //Sets LeftMotor1 to OUTPUT
 pinMode(RightMotor2,OUTPUT);  //Sets RightMotor2 to OUTPUT
 pinMode(LeftMotor2,OUTPUT);  //Sets LeftMotor2 to OUTPUT
}

void Forward() {
    digitalWrite(RightMotor1, HIGH);  //Turns the right "FORWARD PIN" on so the right motor turns forward
    digitalWrite(LeftMotor1, HIGH);  //Turns the left "FORWARD PIN" on so the left motor turns forward
    
    digitalWrite(RightMotor2, LOW);  //Assures that the right "BACKWARD PIN" is off so the robot wouldn't have malifunctions
    digitalWrite(LeftMotor2, LOW);  //Assures that the left "BACKWARD PIN" is off so the robot wouldn't have malifunctions
}

void TurnLeft() {
    digitalWrite(LeftMotor1, HIGH);   //Turns the left "FORWARD PIN" on so the left motor turns forward 
    digitalWrite(RightMotor2, HIGH); //Turns the right "BACKWARD PIN" on so the right motor turns backward 

    digitalWrite(LeftMotor2, LOW);    //Assures that the left "BACKWARD PIN" is off so the robot wouldn't have malifunctions
    digitalWrite(RightMotor1, LOW);  //Assures that the right "FORWARD PIN" is off so the robot wouldn't have malifunctions
}

void TurnRight() {
    digitalWrite(LeftMotor2, HIGH);   //Turns the left "BACKWARD PIN" on so the left motor turns forward 
    digitalWrite(RightMotor1, HIGH); //Turns the right "FORWARD PIN" on so the right motor turns backward 

    digitalWrite(LeftMotor1, LOW);    //Assures that the left "FORWARD PIN" is off so the robot wouldn't have malifunctions
    digitalWrite(RightMotor2, LOW);  //Assures that the right "BACKWARD PIN" is off so the robot wouldn't have malifunctions  
}

void Stop(){
    digitalWrite(LeftMotor2, LOW);     //Turns the left "BACKWARD PIN" off so the robot stops 
    digitalWrite(RightMotor1, LOW);   //Turns the left "FORWARD PIN" off so the robot stops 
    digitalWrite(LeftMotor1, LOW);   //Turns the right "FORWARD PIN" off so the robot stops  
    digitalWrite(RightMotor2, LOW); //Turns the right "BACKWARD PIN" off so the robot stops 
}
void race() {
 int valRR = analogRead(sensRR);       //Sets the sensRR's mode to its reading
 int valMidR = analogRead(sensMidR);  //Sets the sensMidR's mode to its reading
 int valMidL = analogRead(sensMidL); //Sets the sensMidL's mode to its reading
 int valLL = analogRead(sensLL);    //Sets the sensLL's mode to its reading


  if((valMidR == 1 & valMidL == 1) & (valRR == 0 & valLL == 0)) //If the robot is on the correct path then...
  {
 Forward;
  }else{
    if((valMidR == 1 & valMidL == 1 & valLL == 1 & valRR == 0) || ( valMidL == 1 & valLL == 1 & valRR == 0 & valMidR == 0)) //If there is left 90° corner or something...
    {
      TurnLeft;
    }else{
      if((valMidL == 1 & valMidR == 1 & valRR == 1 & valLL == 0) || ( valMidR == 1 & valRR == 1 & valLL == 0 & valMidL == 0)) //If there is right 90° corner or something...
      {
        TurnRight;
      }else{
        if(valMidR == 0 & valMidL == 0 & valRR == 0 & valLL == 0) //If everything is white...
        {
          Forward;
        }else{
          if(valMidR == 1 & valMidL == 1 & valRR == 1 & valLL == 1) //If everything is black...
          {
            Forward;
            if(valMidR == 0 & valMidL == 0 & valRR == 0 & valLL == 0){
              Stop;
            }
          }
        }
      }
    }
  }
  }

void loop() {
  race;
}