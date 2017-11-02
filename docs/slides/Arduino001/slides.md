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
thingThatHappensOnce()
otherThingThatsOnlyRunOnce()
while (true) {
  thingThatHappensOverAndOVer()
}
```

---
