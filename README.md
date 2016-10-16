# CapacitiveTouchLamp
Making an interactive lamp through the use of capacitive touch, Raspberry Pi, and python

# Capacitive Touch Library

Will be using this one: https://github.com/adafruit/Adafruit_Python_MPR121

`git clone https://github.com/adafruit/Adafruit_Python_MPR121.git`

# Operating System

Get newest Raspian, probably Jessie: https://www.raspberrypi.org/downloads/raspbian/

# Hardware

Capacitive touch hardware: https://learn.adafruit.com/adafruit-mpr121-12-key-capacitive-touch-sensor-breakout-tutorial/downloads?view=all

# Setup

Software: 

`sudo apt-get update`
`sudo apt-get install build-essential python-dev python-smbus python-pip git`

`cd ~`
`git clone https://github.com/adafruit/Adafruit_Python_MPR121.git`

`cd Adafruit_Python_MPR121`
`sudo python setup.py install`

`cd examples`
`sudo python simpletest.py`

Hardware: ![Circuit Diagram](/diagram.png?raw=true "Circuit Diagram")
