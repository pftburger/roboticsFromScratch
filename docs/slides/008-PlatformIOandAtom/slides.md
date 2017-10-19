
class: middle, center

# NODE17 IOT
## Hardware toolchain

---

#Why?

* Arduino IDE is cute, and a nice tool to intro people new to coding
* But its got no auto-complete
* Its terrible at managing indentation
* Board and port settings are global.... WHY!?
* Its white and I'm racist

---

#What?

* [Stino](https://github.com/Robot-Will/Stino) for sublime
* PlatformIO for Atom
* Arduino for Eclipse

---
#PlatformIO and Atom

* Nice balance of functionality and learning curve
* Pwetttyyy
![pretty](https://cl.ly/lDiT/Image%202017-06-20%20at%2011.38.47%20AM.gif)

---

#Atom

* <3
* Super super great auto-complete
* Works for all your code, js, cpp, html, cats
* did i mention the amazing auto-complete
* it comes in dark

---

#PlatformIO
## http://platformio.org/get-started

* Plugs into Atom so very nicely
  * +1 for not rolling your own solution (PS. dont roll your own solutions....)
* Amazing board support.
* Wonderful Library manager
* Realtime debug...


---

+ Install Atom
https://atom.io/

+ Install PlatformIO

---

# Installing PlatformIO
+ Open Atom Package Manager
  + Windows, Menu: File > Settings > Install
  + macOS, Menu: Atom > Preferences > Install
  + Linux, Menu: Edit > Preferences > Install
+ Search for official platformio-ide package
+ Install PlatformIO IDE.

+ If it prompts you to install dependencies, do it
  + Namely clang [from here](http://docs.platformio.org/en/latest/ide/atom.html#ii-clang-for-intelligent-code-completion)

+ Also, anti virus software messes with everything you do, kill it with fire



or use pip
pip install platformio
... although you might then first have to install pip

also.... windows sucks... environmental variables may just not register...
Try just restarting if stuff doesn't work....

---

# Install the driver for the CH340G USB Serial thing

https://wiki.wemos.cc/downloads#downloads

---
