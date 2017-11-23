#include <WEMOS_Motor.h>

/*
 *  Application Name
 *  Short Discription
 *  Your Name
 *  Contact
 *  Date
 *  
 */
 
//Libraries

//Aliases
#define softwareVersion "0.1.0"
#define motorLeftFactor  98
#define motorRightFactor 100
#define pinEcho D7 // Echo Pin, D7 is a constant inherited from the wemos library, automatically imported when we set the board
#define pinTrig D6 // Trigger Pin, likewise, assocaited with the constant D6



//Instances
Motor motorLeft(0x30,_MOTOR_A, 1000);
Motor motorRight(0x30,_MOTOR_B, 1000);
//Variables

//Functions 

void motorsForward(int rate = 100){
  motorLeft.setmotor(_CW, rate * motorLeftFactor);
  motorRight.setmotor(_CCW, rate * motorLeftFactor);
}
void motorsBack(int rate = 100){
  motorLeft.setmotor(_CCW, rate * motorLeftFactor);
  motorRight.setmotor(_CW, rate * motorLeftFactor);
}
void motorsStop(int rate = 100){
  motorLeft.setmotor(_STOP);
  motorRight.setmotor(_STOP);
}


void motorsTurnLeft(){
  motorLeft.setmotor(_CCW,20);
  motorRight.setmotor(_CCW,20);
  delay(900);
  motorsStop();
}

void pulseOut(int pin, int pulseTime){
  //Generate a 10 microsecond pulse on the trigger pin of the ultasonic range finder.
  //Notice that we pull it low first, just to be sure. 
  digitalWrite(pin, LOW);
  delayMicroseconds(2);
  digitalWrite(pin, HIGH);
  delayMicroseconds(pulseTime);
  digitalWrite(pin, LOW);


}

int getDistance(int pinTrigger, int pinEcho){
  //create some LOCAL variables
  int pulseDuration;
  int calculatedDistance;

  //pulse for 10 microseconds
  pulseOut(pinTrigger, 10);
  
  //Use a built in function, pulseIn to wait and calculate the
  //ammount of time the echo took to return, as a spike HIGH on the echo pin
  pulseDuration = pulseIn(pinEcho, HIGH);

  //Do some simple math to calculate the distance (in cm)
  //based on the speed of sound.
  calculatedDistance = pulseDuration / 58.2;
  return calculatedDistance;
  
}

void setup() {
  //Run by the chip once at start
  pinMode(pinTrig, OUTPUT); //Set the trigger pin as an output
  pinMode(pinEcho, INPUT);  //Set the echo pin as an input
  Serial.begin(115200);
  Serial.println("V"+String(softwareVersion));
  
}


void loop() {
  //Run by the chip over and over after the setup function has finished

  
  motorsForward(25);
  int distance = getDistance(pinTrig, pinEcho);
  Serial.println("Distance : " + String(distance));
  if (distance<25){
    Serial.println("Turning Left");
    motorsBack(25);
    delay(500);
    motorsTurnLeft();
  }
  

  

}
