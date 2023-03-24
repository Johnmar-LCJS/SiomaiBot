//  Proximity Sensors
#define L_Prox_sen A2
#define R_Prox_sen A1

//  Line Tracing Sensors
#define F_Line_sen A0

//  Ultrasonic Distance Sensor
#define Trig_pin 10
#define Echo_pin 11

// Left Motor A
#define L_Motor_En_pin 5
  //  Motor Rotation Controls
#define L_Input_1 7
#define L_Input_2 8

// Right Motor B
#define R_Motor_En_pin 6
  //  Motor Rotation Controls
#define R_Input_3 13
#define R_Input_4 12

long duration;
int distance;


void setup() {
//  Proximity Sensors
  pinMode(A2,INPUT); //Left Prox IR sen.
  pinMode(A1,INPUT); //Right Prox IR sen.

//  Line Tracing Sensors
  pinMode(A0,INPUT); //Front Line Tracing sen.

//  Ultrasonic Distance Sensor
  pinMode(10,INPUT); //Trigger pin
  pinMode(11,INPUT); //Echo pin

//  Motor Controls
  pinMode(5,OUTPUT); //Enable pin of Left Motor A
  // Left Motor A Rotation Direction Controls  
  pinMode(7,OUTPUT); //Input 1
  pinMode(8,OUTPUT); //Input 2
  
  pinMode(6,OUTPUT); //Enable pin of Right Motor B
  // Right Motor B Rotation Direction Controls  
  pinMode(13,OUTPUT); //Input 3
  pinMode(12,OUTPUT); //Input 4

}

void loop() {

  digitalWrite(Trig_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig_pin, LOW);
  duration = pulseIn(Echo_pin, HIGH);
  
  distance = duration * 0.034 / 2;
  
  if (digitalRead(L_Prox_sen) == 0 && digitalRead(R_Prox_sen) == 0 && distance <= 60) {
    digitalWrite(L_Input_1, HIGH);
    digitalWrite(L_Input_2, LOW);
    digitalWrite(R_Input_3, HIGH);
    digitalWrite(R_Input_4, LOW);
    digitalWrite(L_Motor_En_pin, HIGH);
    digitalWrite(R_Motor_En_pin, HIGH);
  }

  else if (digitalRead(F_Line_sen) == 1) {
      digitalWrite(L_Input_1, LOW);
      digitalWrite(L_Input_2, HIGH);
      digitalWrite(R_Input_3, LOW);
      digitalWrite(R_Input_4, HIGH);
      analogWrite(L_Motor_En_pin, 175);
      analogWrite(R_Motor_En_pin, 175);
      delay(500);
      analogWrite(L_Motor_En_pin, LOW);
      analogWrite(R_Motor_En_pin, LOW);      
  }

  // else if (digitalRead(L_Prox_sen) != 0 && digitalRead(R_Prox_sen) != 0 && distance > 60) {
  //   digitalWrite(L_Input_1, LOW);
  //   digitalWrite(L_Input_2, HIGH);
  //   digitalWrite(R_Input_3, LOW);
  //   digitalWrite(R_Input_4, HIGH);
  //   analogWrite(L_Motor_En_pin, HIGH);
  //   analogWrite(R_Motor_En_pin, HIGH);
  // }
    
   
  
}



