
int outputPin = 3;

void setup() {
  pinMode(12, OUTPUT); //IN2
  pinMode(13, OUTPUT); //IN1
  pinMode(6, OUTPUT); //Enable Pin
  pinMode(3, INPUT);
}
void loop() {
  
  if( digitalRead(outputPin) == HIGH)
{
         digitalWrite(12, LOW);     
}
else                                
{
    delay(100);               
    if( digitalRead(outputPin) == HIGH)    
    {                               
         digitalWrite(12, LOW);      
    }
    else                            
    {
        
        digitalWrite(12, HIGH);     
        digitalWrite(13, LOW);
        digitalWrite(6, HIGH);
        
    }
}
}
