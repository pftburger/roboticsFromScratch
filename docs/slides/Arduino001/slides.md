<!---
class: middle, center
-->

# Robotics from Scratch - Arduino 001
## dMA Winter Semester 2017

---
<!---
class: left
-->

## Outline

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

## Intro to Arduino Basics
+ Getting your environment set up
  + Download and Install
  + Look arround the IDE
  + Connecting a board & uploading code
+ Underlying concepts
  + Voltage [Exercise - Measuring voltage](#exercise---measuring-voltage)
  + Floating inputs
  + Serial [Exercise - PC to PC Serial](#exercise---pc-to-pc-serial)

---

## Basics of Coding
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

## Getting Arduino ( & Micro-controller) specific
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
## Curly Brackets {}

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
## Line ending with the semi colon ;

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
## Line & Block comments

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
## Naming conventions

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
## Looking inside with Serial

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
## Variables

You can think of variables like storage boxes. They allow you to hold on to some value fo later use.
As their name suggests, they are, well, variable.

```javascript
int myVariable = analogRead(A0);  //So, the value that analogRead returns, is saved in myVariable

//some time later, you can recall that value, just by referencing it
if (myVariable < 100 ){
  Serial.println("myVariable < 100 ");
}

```

A note on **scope**

```javascript
int thingOne;  // thingOne is visible to the whole program

void loop(){
  int thingTwo = 5; //thingTwo is visible only within the loop

  while (someCondition) {
    int thingThree = amazingFunction(); // thingThree is visible only within the while loop
  }
}
```

---

Basics of Coding - General coding concepts
## Constants

Constants are like variables but not variable... they are... wait for it, constant.
Some examples are numbers, because 5 is always 5
true and false are also constants.

Within the Arduino language, there are also certain reserved constants that make our lives easier.
I.E
INPUT and OUTPUT
HIGH and LOW
and a few more you will encounter along the way.


---

Basics of Coding - General coding concepts
# Arithmetic

As you would expect, you can do all of the normal mathematical functions simply, like so

```javascript

x = 1 + 4;
y = x - 5;
z = y * 100; //multiply
i = z / 3;  // divide
r = 32 % 5 //modulo, or remainder, IE r = 2
```

Bare in mind though, if you are using integers, division will discard the fractional component.

as well comparison operators

```javascript

x == y  // test if x and y are equals
x != y //
```
Along with those, you also have logical operators

```javascript

x = true && false;  //AND - true only if BOTH operators are true
y = true || false; //OR - true if EITHER of the operators are true
z =

```


---

Basics of Coding - General coding concepts
# Data types

Data on a computer is stored in ones and zeros called Bits.
But we dont want to always have to convert stuff back and forth every time we want to save a number or a sentence in memory or to disk. As such we have a few more complex data types.

Take for example a byte.
A byte is made up of 8 bits.
00000000 is zero
and
11111111 is 255

here are a few others.

```javascript
byte myByte = 100; // a number from 0 to 254 (8bits)
int myInteger = 752; //  a whole number from -32,767 to 32,767 (16 bits)
long myLong = 26472836; // a whole number from -2,147,483,647 to 2,147,483,647 (32 bits)
float myFlaot = 1.7532; // a fraction, or floating point number with 32 bits
```

We can also have arrays or matrices data

```javascript
int myArray[] = {1,3,5,7,9}; //an array containing the numbers 1 3 5 7 and 9
//we can also set the set the size before hand
int myOtherArray[5];  //an array with 5 positions in it

```

to get or set a specific position in an array we use brackets []

```javascript
int myArray[] = {1,3,5,7,9}; //an array containing the numbers 1 3 5 7 and 9

someNumber = myArray[0] + myArray[3];  //someNumber now equals 5


```

---

Basics of Coding - General coding concepts
# Functions



You can think of functions as blocks of code. You can create a function if you intend to reuse a section of code a few times. It helps keep your code readable and can greatly save time by reducing the amount of code you need to write.

```javascript
void myFunction() {   // a new function called myFunction
  things();
  otherThings();
  moreThings();
}
```

functions can return a result like so

```javascript
int doAThing() {   // notice the int. The data type returned is now expected to be an integer
  int myNiceNum;
  myNiceNum = 7;
  return myNiceNum;
}

result = doAThing();
```
and can take inputs like so

```javascript
int add(int num1, int num2) {   // notice the int. The data type returned is now expected to be an integer
  int total;
  total =  num1 + num2;
  return total;
}

result = add(5,7);  //result is now 12
```
---

Basics of Coding - General coding concepts
# Flow control

Conditionals test a condition. We use them to make our programs smarter than just a list of instructions executed one after another.

```javascript
if (someCondition) {
  doAThing();
}
```
so, if someCondition evaluates to true, doAThing() is run, otherwise the whole code block is skipped
