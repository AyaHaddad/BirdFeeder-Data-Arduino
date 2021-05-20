#include <Servo.h>
Servo myServo;  
int positionServo = 0;                          //Init position of the servo 0°

int Sensor = 2;

int PoidsGraines = 4;

void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600);             // We initialize serial connection so that we could print values from sensor.
  
  pinMode(Sensor,INPUT);          //We define pin 2 like an entry for MotionSensor
  
  myServo.attach(9);              //We define pin 9 like an entry for ServoMotor
  myServo.write(positionServo);   //Init positon of the servo to 0°

}

void loop() {
  // put your main code here, to run repeatedly:
  
  if(digitalRead(Sensor)==HIGH){                                      //If the sensor detects smthgs    
    for(positionServo = 0; positionServo <= 180; positionServo++){    //The servo take a 180° position
      myServo.write(positionServo);
      delay(12);                                                      //Servo's speed
  }
    for(positionServo = 180; positionServo >= 0; positionServo--){    //Now the servo go back to he's init position 0°
      myServo.write(positionServo);
      delay(12);        
  }
  PoidsGraines = PoidsGraines - 2;
  } 

;
  if(PoidsGraines <= 0){
    Serial.print("Vide");
    }else{
      Serial.print(PoidsGraines);
      };

//Value who will be usefull to calculate water level %  
// 0% -> 0.85
//25% -> 1.59
//50% -> 1.82
//75% -> 1.99
//100% -> 2.05


int valeurAnalog = analogRead(A3);              //Take the value on Analog 3
float tension = (float) 5*valeurAnalog/1023;    //To calculate the tension

//Now we "convert" tension value to % :
if(tension < 0.85){
  Serial.print(" ");
  Serial.print(tension);
  Serial.print(" ");
  Serial.print("0%");
  Serial.println();
}
else if(tension < 1.59){
  Serial.print(" ");
  Serial.print(tension);
  Serial.print(" ");
  Serial.print("0-25%");
  Serial.println();
}
else if(tension < 1.82){
  Serial.print(" ");
  Serial.print(tension);
  Serial.print(" ");
  Serial.print("25-50%");
  Serial.println();
}
else if(tension < 1.99){
  Serial.print(" ");
  Serial.print(tension);
  Serial.print(" ");
  Serial.print("50-75%");
  Serial.println();
}
else if(tension < 2.05){
  Serial.print(" ");
  Serial.print(tension);
  Serial.print(" ");
  Serial.print("75-100%");
  Serial.println();
}
else{
  Serial.print(" ");
  Serial.print(tension);
  Serial.print(" ");
  Serial.print("100%");
  Serial.println();
  

}

delay(2000);
}
