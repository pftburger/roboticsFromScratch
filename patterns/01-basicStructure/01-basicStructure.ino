/*
 *  Arduino Patterns 
 *  Basic code structure
 *  Theron Burger, dMA Uni Hannover 
 *  burger@aida.uni-hannover.de
 *  22 Nov 2017
 *  
 */

 
//Libraries (just files like this one, but external and just referenced here)
#include "WEMOS_Motor.h"

//Aliases, or shortcuts, for parameters that dont change during runtime
//Things like pin numbers, motor directions, etc
#define sensorPin  5
#define turnDistance  15
#define turnTime 1.3



#define softwareVersion "1.0.0" 

/*
 *  Note on Versioning :
 *  V X.Y.Z
 *  X is a major version. This is for large revisions,
 *  like entire rewrites of the code
 *  X > 1 is beta
 *  Y is for minor versions, 
 *  You should increase this every time you modify the interface 
 *  betweem your software and other things
 *  Z is mainly for bugfixes that dont change anything external
 *  Most of the time you can leave this out
 */


//Instances
Motor motorLeft(0x30,_MOTOR_A, 1000); //motorLeft is now  an insance(think clone) of the Motor prototype
Motor motorRight(0x30,_MOTOR_B, 1000); 
//Variables
//Variables used for the basic opperation of your code


//Functions 
//Little bits of code packed up into functions to keep your code sane


void setup() {
  //Run by the chip once at start
  Serial.begin(115200); //No need to go slower unless something fails. 
  Serial.println("V"+String(softwareVersion));

}

void loop() {
  //Run by the chip over and over after the setup function has finished

}
