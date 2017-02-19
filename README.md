## Introduction
Making an interactive lamp through the use of capacitive touch, Raspberry Pi, python, Arduino, and NeoPixels.

## YouTube

YouTube: 

## Set Up

I am using a Raspberry Pi 2, but you should be able to use almost any version of the Raspberry Pi without issue. I have the project folder on my Pi's Desktop, but you can clone it where you like. Most of the code is in the `examples/` folder. You might need to install the capacitive touch library I'm using: https://github.com/adafruit/Adafruit_Python_MPR121

Commands I would use to set up the environment:

    sudo apt-get update
    sudo apt-get install build-essential python-dev python-smbus python-pip git

    cd ~/Desktop
    git clone https://github.com/cwalk/CapacitiveTouchLamp.git

    cd CapacitiveTouchLamp/
    sudo python setup.py install

To run the code:

    cd examples/
    sudo python cap.py

## Cron job

What I did was setup a cron job to run my `launcher.sh` script everytime my Pi reboots. This makes it easy because all I have to do is add power to the Pi, and the project starts working after the Pi boots. Now I made `launcher.sh` run on reboot, but all this shell script does is navigate to my project directory, and run `sudo python cap.py`. Please feel free to just set up a cron job to run `sudo python cap.py` instead.

For more help, check out: https://www.raspberrypi.org/documentation/linux/usage/cron.md and http://www.instructables.com/id/Raspberry-Pi-Launch-Python-script-on-startup/

## How the Code works

Basically the `cap.py` file is always running, thanks to the cron job. This listens for a capacitive touch from the sensor. If we get one, we generate a random number, depending on which Pin was detected. That number spins off 2 threads: 1 will play the audio file associated with the generated number, and the other will send a serial communication to the Arduino, that corresponds to the audio file being played.

Meanwhile, the Arduino, which is connected to the Pi through Serial, recieves that and will play a lighting animation that correlates to the audio file, with precise timing to the length of the audio file.

## Circuit Diagram

Here is the circuit diagram I made.

Pi -> MPR121 Capacitive Touch sensor:

    3.3V -> VIN
    GND -> GND
    SCL -> SCL
    SDA -> SDA

Hardware: ![Circuit Diagram](/diagram.png?raw=true "Circuit Diagram")

Arduino -> NeoPixel:
    
    5V -> 5V
    GND -> GND
    Pin 6 -> Data In

My code uses pins 0, 4, 6, 10, and 11 for sensing touch from the MPR121 capacitive touch sensor.
