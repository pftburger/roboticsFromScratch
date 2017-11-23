

/* 
Robotics From Scratch 2017
Ultrasonic range finder on the Wemos D1 Mini
Example 03

Integrating a condition to trigger the LED


*/


//Pin definitions
#define pinEcho D7 // Echo Pin, D7 is a constant inherited from the wemos library, automatically imported when we set the board
#define pinTrig D6 // Trigger Pin, likewise, assocaited with the constant D6

//Global Variable Definitions
int distance; 
 
void setup()
{
  Serial.begin (9600);
  pinMode(pinTrig, OUTPUT); //Set the trigger pin as an output
  pinMode(pinEcho, INPUT);  //Set the echo pin as an input
  pinMode(LED_BUILTIN, OUTPUT); //Set the built in LED (referenced from the constant LED_BUILTIN) to an output
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

void loop()
{

  distance = getDistance(pinTrig, pinEcho);
  //Print the calculated distance out over seril to help us check things
  String distAsString = String(distance); //convert the integer to a string
  Serial.print("Distance : " + distAsString);

  if (distance <=  20){
    Serial.println("  <=  20, turning LED on");
    digitalWrite(LED_BUILTIN, LOW); //on the wemos, the LED is INVERSE!! (Boo...) so LOW is on 
  } else {
    Serial.println("  >  20, , turning LED off");
    digitalWrite(LED_BUILTIN, HIGH);
    
  }

  
  //Delay the program 50ms before the next loop
  //This slows down the program and keeps the outputs somewhere were our
  //slow brains can keep up.
  delay(100);
}
