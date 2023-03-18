//  Proximity Sensors
#define L_Prox_sen 9
#define R_Prox_sen 3
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


void setup() {
//  Proximity Sensors
  pinMode(9,INPUT); //Left Prox IR sen.
  pinMode(3,INPUT); //Right Prox IR sen.
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
  
}

void traverseLeft() {

}

void traverseRight() {

}

void reverse() {
  
}

void loop() {
  // put your main code here, to run repeatedly:

}
