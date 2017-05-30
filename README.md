# OMSI_Satelite_Orbits
Satelite Orbits, Design Force Sales project

An Arduino Uno monitors an infrared sensor on digital Pin 6.  When the sensor goes low the uno pulls digital Pin 10 high turning on the Globe motor and
pulls digital Pin 3 high turning on the constant current LED driver.  The globe and UV leds stay on for 3 minutes after the sensor is triggered.

The infrared non-contact sensor is a QRB1134: https://www.digikey.com/products/en?keywords=qrb1134
A current limiting resistor of 150ohm maintains a voltage of 1.2V and 21ma across the IR LED.  The resistor resides on the protoboard shield.
When the swinging arm crosses in front of the sensor, digital PIN 6 goes low and the timer is started.

The UV LED driver consists of a power mosfet, a transistor and a current setting resistor of 33ohm maintaining 22ma through the LEDs. 12 volts powers three UV LEDs in series. 
LEDs are RL5-UV0430-400 sold by superbrightLEDs.com: https://www.superbrightleds.com/moreinfo/through-hole/5mm-uv-led-30-degree-viewing-angle-400-nm-40mw/630/1905/
The LED driver circuit resides on the protoshield ontop of the uController.

![alt text](https://github.com/hydronics2/OMSI_Satelite_Orbits/blob/master/block_diagram.JPG)

R1 is 150ohm

R2 is 33ohm

R3 is 150ohm

Q1 is 2N3904

Q2 is FQP30N06L


UV LEDs: https://www.superbrightleds.com/moreinfo/through-hole/5mm-uv-led-30-degree-viewing-angle-400-nm-40mw/630/1905/

Infrared non-contact snesor: https://www.digikey.com/products/en?keywords=qrb1134

Power Switchtail: https://www.sparkfun.com/products/10747

MicroController: https://www.sparkfun.com/products/13975


