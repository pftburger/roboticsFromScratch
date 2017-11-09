/* 
Robotics From Scratch 2017
Ultrasonic range finder on the Wemos D1 Mini


*/

//Pin definitions
#define pinEcho D7 // Echo Pin, D7 is a constant inherited from the wemos library, automatically imported when we set the board
#define pinTrig D6 // Trigger Pin, likewise, assocaited with the constant D6

//Variable Definitions
int duration; //How long the pin took to echo back
int distance; 
 
void setup()
{
  Serial.begin (9600);
  pinMode(pinTrig, OUTPUT); //Set the trigger pin as an output
  pinMode(pinEcho, INPUT);  //Set the echo pin as an input
}
 
void loop()
{
  //Generate a 10 microsecond pulse on the trigger pin of the ultasonic range finder.
  //Notice that we pull it low first, just to be sure. 
  digitalWrite(pinTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(pinTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinTrig, LOW);

  //Then we use a built in function, pulseIn to wait and calculate the
  //ammount of time the echo took to return, as a spike HIGH on the echo pin
  duration = pulseIn(pinEcho, HIGH);

  //Do some simple math to calculate the distance (in cm)
  //based on the speed of sound.
  distance = duration / 58.2;

  //Print the calculated distance out over seril to help us check things
  Serial.println(distance);

  
  //Delay the program 50ms before the next loop
  //This slows down the program and keeps the outputs somewhere were our
  //slow brains can keep up.
  delay(50);
}
