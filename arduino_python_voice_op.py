import serial
import time
import pyttsx3
import os
import pandas as pd


engine = pyttsx3.init()

# set up the serial line
ser = serial.Serial("COM9", 9600)

# Read and record the data
data = []  # empty list to store the data
for i in range(50):

    b = ser.readline()  # read a byte string
    string_n = b.decode()  # decode byte string into Unicode
    string = string_n.rstrip()  # remove \n and \r

    # convert string to float

    print(string)
    data.append(string)  # add to the end of data list
    time.sleep(0.1)  # wait (sleep) 0.1 seconds

ser.close()
# show the data

for line in data:
    l = int(line)
    if l < 50:
        engine.say("obstacle detected change direction")
        engine.runAndWait()
        break
