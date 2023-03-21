//  Proximity Sensors
#define L_Prox_sen A3
#define R_Prox_sen A4
#define F_Prox_sen A2

//  Line Tracing Sensors
#define L_Line_sen A1
#define R_Line_sen A0

//  Ultrasonic Distance Sensor
#define Trig_pin 10
#define Echo_pin 11

// Left Motor A
#define L_Motor_En_pin 6
  //  Motor Rotation Controls
#define L_Input_1 13
#define L_Input_2 12

// Right Motor B
#define R_Motor_En_pin 5
  //  Motor Rotation Controls
#define R_Input_3 7
#define R_Input_4 8

long duration;
int distance;


void setup() {
//  Proximity Sensors
  pinMode(A3,INPUT); //Left Prox IR sen.
  pinMode(A4,INPUT); //Right Prox IR sen.
  pinMode(A2,INPUT); //Front Prox IR sen.

//  Line Tracing Sensors
  pinMode(A1,INPUT); //Left Line Tracing sen.
  pinMode(A0,INPUT); //Right Line Tracing sen.

//  Ultrasonic Distance Sensor
  pinMode(10,INPUT); //Trigger pin
  pinMode(11,INPUT); //Echo pin

//  Motor Controls
  pinMode(6,OUTPUT); //Enable pin of Left Motor A
  // Left Motor A Rotation Direction Controls  
  pinMode(13,OUTPUT); //Input 1
  pinMode(12,OUTPUT); //Input 2
  
  pinMode(5,OUTPUT); //Enable pin of Right Motor B
  // Right Motor B Rotation Direction Controls  
  pinMode(7,OUTPUT); //Input 3
  pinMode(8,OUTPUT); //Input 4

}

void charge() {
  digitalWrite(L_Input_1, HIGH);
  digitalWrite(L_Input_2, LOW);
  digitalWrite(R_Input_3, HIGH);
  digitalWrite(R_Input_4, LOW);
  digitalWrite(L_Motor_En_pin, HIGH);
  digitalWrite(R_Motor_En_pin, HIGH);
  // Unfinished
}

void traverseLeft() {
  digitalWrite(L_Input_1, LOW);
  digitalWrite(L_Input_2, HIGH);
  digitalWrite(R_Input_3, HIGH);
  digitalWrite(R_Input_4, LOW);
  analogWrite(L_Motor_En_pin, 195);
  analogWrite(R_Motor_En_pin, 195);
}

void traverseRight() {
  digitalWrite(L_Input_1, HIGH);
  digitalWrite(L_Input_2, LOW);
  digitalWrite(R_Input_3, LOW);
  digitalWrite(R_Input_4, HIGH);
  analogWrite(L_Motor_En_pin, 195);
  analogWrite(R_Motor_En_pin, 195);
}

void radialSearch() {
  digitalWrite(L_Input_1, LOW);
  digitalWrite(L_Input_2, HIGH);
  digitalWrite(R_Input_3, HIGH);
  digitalWrite(R_Input_4, LOW);
  analogWrite(L_Motor_En_pin, 195);
  analogWrite(R_Motor_En_pin, 195);
}

void stop() {
  digitalWrite(L_Motor_En_pin, LOW);
  digitalWrite(R_Motor_En_pin, LOW);
}

void reverse() {
  digitalWrite(L_Input_1, HIGH);
  digitalWrite(L_Input_2, LOW);
  digitalWrite(R_Input_3, HIGH);
  digitalWrite(R_Input_4, LOW);
  analogWrite(L_Motor_En_pin, 175);
  analogWrite(R_Motor_En_pin, 175);
  delay(1000)
  analogWrite(L_Motor_En_pin, LOW);
  analogWrite(R_Motor_En_pin, LOW);
// Unfinished  
}

void loop() {

  digitalWrite(Trig_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig_pin, LOW);
  duration = pulseIn(Echo_pin, HIGH);
  
  distance = duration * 0.034 / 2;
  
  while (digitalRead(F_Prox_sen) == 0 && distance <= 60) {
    charge();
  }

  else if (digitalRead(L_Line_sen) == 0 || digitalRead(R_Line_sen) == 0) {
    reverse();
  }

  else if (digitalRead(L_Prox_sen) == 0 && !digitalRead(R_Prox_sen) == 0) {
    traverseLeft();
  }

  else if (!digitalRead(L_Prox_sen) == 0 && digitalRead(R_Prox_sen) == 0) {
    traverseRight();
  }

  else if (!digitalRead(L_Prox_sen) && !digitalRead(R_Prox_sen) && !digitalRead(F_Prox_sen) && !digitalRead(L_Prox_sen) && !digitalRead(R_Prox_sen) && distance > 60) {
    stop();
    delay(100);
    radialSearch();
  }  
  
}



