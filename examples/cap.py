import sys
import time
import os
import serial
import random
import RPi.GPIO as GPIO
import Adafruit_MPR121.MPR121 as MPR121
import threading
from threading import Thread

flag1 = 0
flag2 = 0
randomInt = 0
ser = serial.Serial('/dev/ttyACM0', 9600)

#Defining audio files

#darkSide
def bidding():
	global flag1
	os.system('aplay audio/darkSide/bidding.wav')
	flag1 = 0

def breath():
	global flag1
	os.system('aplay audio/darkSide/breath.wav')
	flag1 = 0

def darkside():
	global flag1
	os.system('aplay audio/darkSide/darkside.wav')
	flag1 = 0

def DarthLsbr():
	global flag1
	os.system('aplay audio/darkSide/DarthLsbr.wav')
	flag1 = 0

def dontfail():
	global flag1
	os.system('aplay audio/darkSide/dontfail.wav')
	flag1 = 0

def failed():
	global flag1
	os.system('aplay audio/darkSide/failed.wav')
	flag1 = 0

def father():
	global flag1
	os.system('aplay audio/darkSide/father.wav')
	flag1 = 0

def haveyou():
	global flag1
	os.system('aplay audio/darkSide/haveyou.wav')
	flag1 = 0

def noescape():
	global flag1
	os.system('aplay audio/darkSide/noescape.wav')
	flag1 = 0

def power():
	global flag1
	os.system('aplay audio/darkSide/power.wav')
	flag1 = 0

def theforce():
	global flag1
	os.system('aplay audio/darkSide/theforce.wav')
	flag1 = 0

def vader():
	global flag1
	os.system('aplay audio/darkSide/vader.wav')
	flag1 = 0

def waiting():
	global flag1
	os.system('aplay audio/darkSide/waiting.wav')
	flag1 = 0

#empire
def imperial():
	global flag1
	os.system('aplay audio/empire/imperial.wav')
	flag1 = 0

#lightSide
def impossible():
	global flag1
	os.system('aplay audio/lightSide/impossible.wav')
	flag1 = 0

def LukeLsbr():
	global flag1
	os.system('aplay audio/lightSide/LukeLsbr.wav')
	flag1 = 0

def yoda():
	global flag1
	os.system('aplay audio/lightSide/yoda.wav')
	flag1 = 0

def disturb():
	global flag1
	os.system('aplay audio/lightSide/disturb.wav')
	flag1 = 0

def force1():
	global flag1
	os.system('aplay audio/lightSide/force1.wav')
	flag1 = 0

def force2():
	global flag1
	os.system('aplay audio/lightSide/force2.wav')
	flag1 = 0

def strongam():
	global flag1
	os.system('aplay audio/lightSide/strongam.wav')
	flag1 = 0

def try_not():
	global flag1
	os.system('aplay audio/lightSide/try_not.wav')
	flag1 = 0

#logo
def mainthemeshort():
	global flag1
	os.system('aplay audio/logo/mainthemeshort.wav')
	flag1 = 0

#rebel
def c3po():
	global flag1
	os.system('aplay audio/rebel/c3po.wav')
	flag1 = 0

def helpme():
	global flag1
	os.system('aplay audio/rebel/helpme.wav')
	flag1 = 0

def r2d2_1():
	global flag1
	os.system('aplay audio/rebel/r2d2_1.wav')
	flag1 = 0

def r2d2_2():
	global flag1
	os.system('aplay audio/rebel/r2d2_2.wav')
	flag1 = 0

def roar():
	global flag1
	os.system('aplay audio/rebel/roar.wav')
	flag1 = 0

def stuck_up():
	global flag1
	os.system('aplay audio/rebel/stuck_up.wav')
	flag1 = 0

def thankme():
	global flag1
	os.system('aplay audio/rebel/thankme.wav')
	flag1 = 0

#Defining Light functions

#darkSide
def biddingLight():
	global flag2
	ser.write('a')
	flag2 = 0

def breathLight():
	global flag2
	ser.write('b')
	flag2 = 0

def darksideLight():
	global flag2
	ser.write('c')
	flag2 = 0

def DarthLsbrLight():
	global flag2
	ser.write('d')
	flag2 = 0

def dontfailLight():
	global flag2
	ser.write('e')
	flag2 = 0

def failedLight():
	global flag2
	ser.write('f')
	flag2 = 0

def fatherLight():
	global flag2
	ser.write('g')
	flag2 = 0

def haveyouLight():
	global flag2
	ser.write('h')
	flag2 = 0

def noescapeLight():
	global flag2
	ser.write('i')
	flag2 = 0

def powerLight():
	global flag2
	ser.write('j')
	flag2 = 0

def theforceLight():
	global flag2
	ser.write('k')
	flag2 = 0

def vaderLight():
	global flag2
	ser.write('l')
	flag2 = 0

def waitingLight():
	global flag2
	ser.write('m')
	flag2 = 0

#empire
def imperialLight():
	global flag2
	ser.write('n')
	flag2 = 0

#lightSide
def impossibleLight():
	global flag2
	ser.write('o')
	flag2 = 0

def LukeLsbrLight():
	global flag2
	ser.write('p')
	flag2 = 0

def yodaLight():
	global flag2
	ser.write('q')
	flag2 = 0

def disturbLight():
	global flag2
	ser.write('r')
	flag2 = 0

def force1Light():
	global flag2
	ser.write('s')
	flag2 = 0

def force2Light():
	global flag2
	ser.write('t')
	flag2 = 0

def strongamLight():
	global flag2
	ser.write('u')
	flag2 = 0

def try_notLight():
	global flag2
	ser.write('v')
	flag2 = 0

#logo
def mainthemeshortLight():
	global flag2
	ser.write('w')
	flag2 = 0

#rebel
def c3poLight():
	global flag2
	ser.write('x')
	flag2 = 0

def helpmeLight():
	global flag2
	ser.write('y')
	flag2 = 0

def r2d2_1Light():
	global flag2
	ser.write('z')
	flag2 = 0

def r2d2_2Light():
	global flag2
	ser.write('{')
	flag2 = 0

def roarLight():
	global flag2
	ser.write('|')
	flag2 = 0

def stuck_upLight():
	global flag2
	ser.write('}')
	flag2 = 0

def thankmeLight():
	global flag2
	ser.write('~')
	flag2 = 0

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
    randomInt = 0

	#darkSide
    if cap.is_touched(8) and flag1 == 0 and flag2 == 0:
    	print('Pin 8 is being touched!')
	flag1 = 1
	flag2 = 1
	#ser.write('1-13')
	randomInt = random.randint(1, 13)
	print(randomInt)
	#Thread(target = yoda).start()
	#Thread(target = greenLight).start()
	if randomInt == 1:
		Thread(target = bidding).start()
		Thread(target = biddingLight).start()
	elif randomInt == 2:
		Thread(target = breath).start()
		Thread(target = breathLight).start()
	elif randomInt == 3:
		Thread(target = darkside).start()
		Thread(target = darksideLight).start()
	elif randomInt == 4:
		Thread(target = DarthLsbr).start()
		Thread(target = DarthLsbrLight).start()
	elif randomInt == 5:
		Thread(target = dontfail).start()
		Thread(target = dontfailLight).start()
	elif randomInt == 6:
		Thread(target = failed).start()
		Thread(target = failedLight).start()
	elif randomInt == 7:
		Thread(target = father).start()
		Thread(target = fatherLight).start()
	elif randomInt == 8:
		Thread(target = haveyou).start()
		Thread(target = haveyouLight).start()
	elif randomInt == 9:
		Thread(target = noescape).start()
		Thread(target = noescapeLight).start()
	elif randomInt == 10:
		Thread(target = power).start()
		Thread(target = powerLight).start()
	elif randomInt == 11:
		Thread(target = theforce).start()
		Thread(target = theforceLight).start()
	elif randomInt == 12:
		Thread(target = vader).start()
		Thread(target = vaderLight).start()
	elif randomInt == 13:
		Thread(target = waiting).start()
		Thread(target = waitingLight).start()

	#empire
    if cap.is_touched(5) and flag1 == 0 and flag2 == 0:
	print('Pin 5 is being touched!')
	flag1 = 1
        flag2 = 1
	#ser.write('14')
    	Thread(target = imperial).start()
    	Thread(target = imperialLight).start()

	#lightSide	
    if cap.is_touched(11) and flag1 == 0 and flag2 == 0:
	print('Pin 11 is being touched!')
	flag1 = 1
	flag2 = 1
	#ser.write('15-22')
	randomInt = random.randint(15, 22)
	print(randomInt)
	#Thread(target = logo).start()
	#Thread(target = logoLight).start()
	if randomInt == 15:
		Thread(target = impossible).start()
		Thread(target = impossibleLight).start()
	elif randomInt == 16:
		Thread(target = LukeLsbr).start()
		Thread(target = LukeLsbrLight).start()
	elif randomInt == 17:
		Thread(target = yoda).start()
		Thread(target = yodaLight).start()
	elif randomInt == 18:
		Thread(target = disturb).start()
		Thread(target = disturbLight).start()
	elif randomInt == 19:
		Thread(target = force1).start()
		Thread(target = force1Light).start()
	elif randomInt == 20:
		Thread(target = force2).start()
		Thread(target = force2Light).start()
	elif randomInt == 21:
		Thread(target = strongam).start()
		Thread(target = strongamLight).start()
	elif randomInt == 22:
		Thread(target = try_not).start()
		Thread(target = try_notLight).start()

	#logo
    if cap.is_touched(0) and flag1 == 0 and flag2 == 0:
	print('Pin 0 is being touched!')
	flag1 = 1
	flag2 = 1
	#ser.write('23')
	Thread(target = mainthemeshort).start()
	Thread(target = mainthemeshortLight).start()

	#rebel
    if cap.is_touched(4) and flag1 == 0 and flag2 == 0:
	print('Pin 4 is being touched!')	
	flag1 = 1
	flag2 = 1
	#ser.write('24-30')
	randomInt = random.randint(24, 30)
	print(randomInt)
	#Thread(target = vaderBreathing).start()
	#Thread(target = redLight).start()
	if randomInt == 24:
		Thread(target = c3po).start()
		Thread(target = c3poLight).start()
	elif randomInt == 25:
		Thread(target = helpme).start()
		Thread(target = helpmeLight).start()
	elif randomInt == 26:
		Thread(target = r2d2_1).start()
		Thread(target = r2d2_1Light).start()
	elif randomInt == 27:
		Thread(target = r2d2_2).start()
		Thread(target = r2d2_2Light).start()
	elif randomInt == 28:
		Thread(target = roar).start()
		Thread(target = roarLight).start()
	elif randomInt == 29:
		Thread(target = stuck_up).start()
		Thread(target = stuck_upLight).start()
	elif randomInt == 30:
		Thread(target = thankme).start()
		Thread(target = thankmeLight).start()
