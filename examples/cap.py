import sys
import time
import os
import RPi.GPIO as GPIO
import Adafruit_MPR121.MPR121 as MPR121
import threading
import serial
from threading import Thread

flag1 = 0
flag2 = 0
#GPIO.setmode(GPIO.BCM)
#set up GPIO pins as outputs
#GPIO.setup(16,GPIO.OUT)
#GPIO.setup(26,GPIO.OUT)
#red = GPIO.PWM(26, 100)
#green = GPIO.PWM(16, 100)
ser = serial.Serial('/dev/ttyACM0', 9600)

def yoda():
	global flag1
	os.system('aplay yoda.wav')
	flag1 = 0

def luke():
	global flag1
	os.system('aplay LukeLsbr.wav')
	flag1 = 0

def vader():
	global flag1
	os.system('aplay DarthLsbr.wav')
	flag1 = 0

def vaderBreathing():
	global flag1
	os.system('aplay vader.wav')
	flag1 = 0

def greenLight():
	global flag2
	ser.write('1')
	flag2 = 0

def redLight():
	global flag2
	ser.write('3')
	flag2 = 0

#def redLight():
#	global flag2
#	red.start(0)
#	for i in range(0,101):
#               red.ChangeDutyCycle(i)
#               time.sleep(0.02)
#       for i in range(100,-1,-1):
#               red.ChangeDutyCycle(i)
#               time.sleep(0.02)
#	print('flag2 is %d', flag2)
#	flag2 = 0
#	print('flag2 is now %d', flag2)
#	red.stop()	

#def greenLight():
#        global flag2
#        green.start(0)
#        for i in range(0,101):
#                green.ChangeDutyCycle(i)
#                time.sleep(0.02)
#        for i in range(100,-1,-1):
#                green.ChangeDutyCycle(i)
#                time.sleep(0.02)
#        print('flag2 is %d', flag2)
#        flag2 = 0
#        print('flag2 is now %d', flag2)
#        green.stop()

print('Adafruit MPR121 Capacitive Touch Sensor Test')

# Create MPR121 instance.
cap = MPR121.MPR121()

if not cap.begin():
    print('Error initializing MPR121.  Check your wiring!')
    sys.exit(1)

# Main loop to print a message every time a pin is touched.
print('Press Ctrl-C to quit.')
last_touched = cap.touched()
while True:
    current_touched = cap.touched()
    time.sleep(0.25)

    if cap.is_touched(0) and flag1 == 0 and flag2 == 0:
        print('Pin 0 is being touched!')
	flag1 = 1
	flag2 = 1
#	ser.write('1')
	Thread(target = yoda).start()
	Thread(target = greenLight).start()

    if cap.is_touched(4) and flag1 == 0 and flag2 == 0:
	print('Pin 4 is being touched!')
	flag1 = 1
        flag2 = 1
#	ser.write('2')
        Thread(target = luke).start()
        Thread(target = greenLight).start()

    if cap.is_touched(10) and flag1 == 0 and flag2 == 0:
	print('Pin 10 is being touched!')
	flag1 = 1
	flag2 = 1
#	ser.write('3')
	Thread(target = vader).start()
	Thread(target = redLight).start()

    if cap.is_touched(11) and flag1 == 0 and flag2 == 0:
	print('Pin 11 is being touched!')	
	flag1 = 1
	flag2 = 1
#	ser.write('4')
        Thread(target = vaderBreathing).start()
	Thread(target = redLight).start()
