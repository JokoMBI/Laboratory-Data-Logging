import sys
import glob
import serial
import time

#open port ...t.d.: implement autodetect-> which port has to be opened?
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

c = ""      #Serial command variable
msg = ""    #Serial incomming message
value = ""  #numeric value (not really
            #parsed until now, just the first 4 chars of the message)

time.sleep(0.3) #waiting for initializing port and receiving a message containing
                #information about the sensor

if port.inWaiting() > 0:    #if serial data is available
    print(port.readline())  #print the init message

    
#the following will be the "ask for temperature or humidity" function
while True: 


    answer = input("t or h?")   #what do you want to know, temperature or humidity?
                                #later the value will be received from the master function
    
    port.flushInput()           #clear the input buffer to be shure, the value is actual

    #asking for temperature
    if answer == "t":
        c = "t"
        port.write(c.encode())  #send command
        c = ""
        
    #asking for humidity
    if answer == "h":
        c = "h"
        port.write(c.encode())  #send command
        c = ""

    time.sleep(0.05)            #buffering time
    
    if port.inWaiting() > 0:
        msg = port.readline()   #read incoming message
        
        value = msg[0:4]        #take the first 4 chars
        print(value)            #and print it
        value = ""
        msg= ""
