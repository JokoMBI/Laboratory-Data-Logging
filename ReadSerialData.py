import sys
import glob
import serial
import time


port =serial.Serial(
    "/dev/ttyUSB0",
    baudrate=9600,
    parity=serial.PARITY_NONE,
    stopbits=serial.STOPBITS_ONE,
    bytesize=serial.EIGHTBITS,
    writeTimeout = 0,
    timeout = 10,
    rtscts=False,
    dsrdtr=False,
    xonxoff=False)

time.sleep(0.5)
print(port.readline())

while True:
        
    while port.inWaiting() >0:
        print(port.readline())
        
    c = ""
    answer = input("t or h?")
    if answer == "t":
        c = "t"
        port.write(c.encode())

    if answer == "h":
        c = "h"
        port.write(c.encode())

