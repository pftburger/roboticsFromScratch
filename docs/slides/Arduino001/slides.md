<!---
class: middle, center
-->

# Robotics from Scratch - Arduino 001
## dMA Winter Semester 2017

---
<!---
class: left
-->

# Outline

+ Intro to Arduino Basics
  + Getting your environment set up
  + Underlying concepts
+ Basics of Coding
  + Structure
  + Good Ideas
  + Looking inside with Serial
  + General coding concepts
+ Getting Arduino ( & Micro-controller) specific
  + Digital IO
  + Analog IO
  + Time, Math & Random
  + Binding it together

---

# Intro to Arduino Basics
+ Getting your environment set up
  + Download and Install
  + Look arround the IDE
  + Connecting a board & uploading code
+ Underlying concepts
  + Voltage [Exercise - Measuring voltage](#exercise---measuring-voltage)
  + Floating inputs
  + Serial [Exercise - PC to PC Serial](#exercise---pc-to-pc-serial)

---

# Basics of Coding
  + Structure
    + Setup & Loop [Exercise - One Blink Vs Many](#exercise---oneblink)
    + Curly Brackets {}
    + Line ending with the semi colon ;
  + Good Ideas
    + Line comments
    + Block comments
  + Looking inside with Serial
  + General coding concepts
    + Variables [Exercise---](#exercise)
    + Constants [Exercise---](#exercise)
    + Arithmetic [Exercise---](#exercise)
    + Data types [Exercise---](#exercise)
    + Functions [Exercise---](#exercise)
    + Conditionals [Exercise---](#exercise)
    + Flow control [Exercise---](#exercise)

---

# Getting Arduino ( & Micro-controller) specific
+ Digital IO [Exercise---](#ex)
+ Analog IO [Exercise---](#ex)
+ Time, Math & Random [Exercise---](#ex)
+ Binding it together
  + [Exercise---](#ex)
  + [Exercise---](#ex)
  + [Exercise---](#ex)
  + [Exercise---](#ex)
    +


---

Getting your environment set up
## Download and Install

---

Getting your environment set up
## Look arround the IDE

---

Getting your environment set up
## Connecting a board & uploading code

---

Underlying concepts
## Voltage

---

Underlying concepts
## [](#exercise-measuring-voltage)Exercise - Measuring voltage


---

Underlying concepts
## Floating inputs

---

Underlying concepts
## Serial

---

Underlying concepts
## [](#exercise---pc-to-pc-serial)Exercise - PC to PC Serial


---

Basics of Coding - Structure
## Setup & Loop

Most of the time when programming, you will need to first set some stuff up, then run your main program.
You can think of this as a setup phase, that runs once, and a main loop phase, that repeats over and over. Any time you open up an Arduino script you will notice

```javascript
void setup() {
  // put your setup code here, to run once:
}
void loop() {
  // put your main code here, to run repeatedly:
}
```

Behind the scenes, the Arduino compiler takes care of looping the loop() function forever, after the setup() function has finished.

you can almost think of it like this
```javascript
thingThatHappensOnce();
otherThingThatsOnlyRunOnce();
while (true) {
  thingThatHappensOverAndOVer();
}
```

---

Basics of Coding - Structure
# Curly Brackets {}

Curly Brackets, sometimes called braces help group code.
For example, in the bare minimum program
```javascript
void setup() {
  // put your setup code here, to run once:
}
void loop() {
  // put your main code here, to run repeatedly:
}
```
After the setup() there is a open brace {
It tells the compiler (The thing that converts what you write to stuff the actual chip can understand) that this is the start of the group of code that belongs to the setup() function
After your done with the setup code, you need to close the group with a }
Any time you need to group code, you will need to enclose it within {}
As a convention, we also indent the lines one tab to make it easier to repeatedly
```javascript
void myThing() {
  wiggle();
  if(stuffIsNice){
    wobble();
  }
}
```
So, wobble() belongs to both the if statement and the myThing() function
whereas wiggle() is only part of the myThing() function

---

Basics of Coding - Structure
# Line ending with the semi colon ;

Your program is made up of statements. The compiler needs to be able to split your program up into a long list of statement. To help it do that, we need to put a semi colon ; at the end of each statement.
Most of the time the compiler will help you by reminding you when you leave it out.

But for the love of all things good and pure please dont just abuse that for fund and do this :
```javascript
this(isOneStatement);
thisIsAnother();
butThisLine(); hasTwo("!");
```

---
Basics of Coding - Good Ideas
# Line & Block comments

The Arduino language is a mashup of Javascript and C++, both of which allow things called comments.
Comments let you, well, leave comments, in your code.
Commenting is good idea. It helps you remember what your writing, and it helps others read your code.
Comments however are not an excuse for making your code impossible to read.
Legible, easy to read code helps you avoid errors.

```javascript
/*  This is a block comments
    Its pretty useful for longer explanations
    Or an intro at the start of your code
*/
thisLineIsExecuted();
//This line is a comment and isn't run either
thisLineIsAlsoRun();


```

---
Basics of Coding - Good Ideas
# Naming conventions

When you coding you will have to come up with lots of names for things. Having consistent rules for naming things will help you remember what things are called, and avoid errors.

A convention I suggest is called camel case, the first letter is lower case, then all new words start with a capital, with no spaces
```javascript
likeSo();
orLikeThis();
```

descriptive names are good.
Short names are good.

```javascript
txtInput12();
//is better than
textBoxInputPage12();
//and both are so much better than
someInputSomewhereDunnoItsNice();
```

---
Basics of Coding
# Looking inside with Serial

In the Arduino IDE, open Examples/Basic/AnalogReadSerial
```javascript
void setup() {
  // Start serial communication at 9600 bits per second:
  // Bits are 1s and 0s, +5v and 0v, so we are capable of sending 9600 of them in one second here
  Serial.begin(9600);
}
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // Encodes the sensorValue into ones and zeros and sends it over to the PC
  Serial.println(sensorValue);
  delay(1);        // delay in between reads for stability
}
```

Open the Examples/Communication/ASCII table and upload it to your Arduino
Once its done, click the little magnifying glass at the top right hand corner to open the serial monitor and take a look at the output.
We can use the Serial.println() command to send data across to the PC

---

When your trying to debug your code, its often helpful to print stuff out to a console or monitor to get an idea of whats actually happening inside your program

```javascript
int sensorValue = analogRead(A0);
Serial.println(sensorValue);
if (sensorValue < 100 ){
  Serial.println("Conditions met, doing a thing");
  doAThing()
}
```

So now, if you dont see your thing happening, you can open up your serial monitor and take a look at the value stored in sensorValue, and see if your (sensorValue < 100 ) is ever true.


---

Basics of Coding - General coding concepts
# Variables

You can think of variables like storage boxes. They allow you to hold on to some value fo later use.
As their name suggests, they are, well, variable.

```javascript
int myVariable = analogRead(A0);  //So, the value that analogRead returns, is saved in myVariable

//some time later, you can recall that value, just by referencing it
if (myVariable < 100 ){
  Serial.println("myVariable < 100 ");
}

```

declaration
scope

---

Basics of Coding - General coding concepts
# Constants

like variables but not variable...
numbers
true false
HIGH LOW
INPUT OUTPUT

---

Basics of Coding - General coding concepts
# Arithmetic

---

Basics of Coding - General coding concepts
# Data types

```javascript
byte myByte = 100 // a number from 0 to 254
int myInteger = 752 //  a whole number from -32,767 to 32,767
long myLong =



```
---

Basics of Coding - General coding concepts
# Functions
---

Basics of Coding - General coding concepts
# Conditionals
---

Basics of Coding - General coding concepts
# Flow control
