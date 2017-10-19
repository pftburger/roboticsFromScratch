# The ESP8266 & The Wemos D1 Mini

+ [Setup](#setup)
  + Adding the board to the board manager
  + Settings
  + Pushing your first sketch - Blinking the LED
+ [MQTT on the ESP8266](#mqtt-on-the-esp8266)
+ Using the ESP with other things
  + [Pinout](#pinout)
  + [Button Shield](#button-shield)
  + [WS2812B RGB Shield](#ws2812b-rgb-shield)
  + [Motor Shield](#motor-shield)
  + [Ultrasonic Distance](#ultrasonic-distance)
  + [OLED](#oled)
  + [Analog Sensors](#analog-sensors)
    + Photo resistor (LDR)
    + IR Reflectance


---
class: middle, center

# [](#setup)Setup

---

+ If you haven't already, [download the Arduino IDE](https://www.arduino.cc/)

---

+ Under file, select preferences
+ under aditional boards, enter

`http://arduino.esp8266.com/stable/package_esp8266com_index.json`

+ and say OK

<img src="images/image-000.png" width="500">


---

+ Under Tools select board and then Bard manager

<img src="images/image-001.png" width="500">


---

+ Search for esp8266
+ and install it

<img src="images/image-002.png" width="600">


---

+ While thats installing, lets go get the [USB Serial Bridge Drivers](https://wiki.wemos.cc/_media/file:ch341ser_win.zip)

<b> Do Not use the Mac driver on macOS Sierra </b>

<b>  Its unsigned and will cause kernel panic </b>

+ On mac, use [these](https://blog.sengotta.net/signed-mac-os-driver-for-winchiphead-ch340-serial-bridge/) drivers instead


+ if you fell into that trap, [here](https://tzapu.com/ch340-ch341-serial-adapters-macos-sierra/) is how to fix it

---

+ Lets send a super simple sketch just blinking the onboard LED to confirm it works
+ There are plenty examples, just open the blink sketch

<img src="images/image-005.png" width="500">

---

+ Select the Comport your device is connected to


<img src="images/image-004.png" width="500">


---

+ and hit the upload arrow
+ it will compile, and upload the code to the board
+ during the upload process the blue LED should flash rapidly

<img src="images/image-006.png" width="500">

---

# [](#mqtt-on-the-esp8266)MQTT on the ESP8266

---

+ In the Arduino IDE go Sketch, libraries and choose Manage libraries


<img src="images/image-007.png" width="500">

---

+ The one we are looking for is called PubSubClient

<img src="images/image-008.png" width="500">

---

+ Lets load the built in example for the esp8266

<img src="images/image-009.png" width="500">

---

+ Change the wifi credentials and put in your MQTT Brokers IP (the elastic ip of your EC2 instance)
+ And open the serial monitor

<img src="images/image-010.png" width="500">

---

+ Lets reconnect to our instance and see if the message is coming through

<img src="images/image-011.png" width="500">

+ and that boys and girls is piped over the internets!

---

# Using the ESP8266 with other things

---

## [](#pinout)Pinout


<img src="images/pinout.jpg" width="600">

---

## [](#oled)OLED

---

+ The Adafruit library for the SDD1306 driver doesnt support our display size, but someone already edited it for us :)
+ download the repo [here](https://github.com/mcauser/Adafruit_SSD1306) as a zip

<img src="images/image-012.png" width="500">

---

+ Add it to the IDE like so

<img src="images/image-013.png" width="500">

---

+ You should now see the library under the (questionable) recomended libraries list.

<img src="images/image-014.png" width="500">

---

+ Now under the examples we should see our LCD size as well

<img src="images/image-015.png" width="500">
