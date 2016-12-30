import serial
import time

ser = serial.Serial('/dev/ttyACM1', 9600)

time.sleep(2)

ser.write('1')

time.sleep(2)
ser.write('2')
time.sleep(2)
ser.write('3')
time.sleep(2)
ser.write('4')

