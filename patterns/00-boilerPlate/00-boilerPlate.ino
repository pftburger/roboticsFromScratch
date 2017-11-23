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
#define logLevel 3
#define sensorPin  5
#define turnDistance  15
#define turnTime 1.3

//Instances

//Variables

//Functions 

void setup() {
  //Run by the chip once at start
  Serial.begin(115200);
  Serial.println("V"+String(softwareVersion));

}

void loop() {
  //Run by the chip over and over after the setup function has finished

}
