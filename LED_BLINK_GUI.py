from tkinter import *
import tkinter.font
import RPi.GPIO as GPIO
GPIO.setmode(GPIO.BCM)
from gpiozero import LED 

## hardware
red_led = LED(14)
blue_led = LED(15)
green_led = LED(16)

## GUI DEFINITIONS
win = Tk()
win.title("LED CONTROLLER")
myFont = tkinter.font.Font(family='Times', size=15, weight= "bold", slant= "italic")
val = IntVar()

## EVENT FUNCTIONS
def ledToggle():
    var = val.get()
    if var == 1:
        red_led.on()
        blue_led.off()
        green_led.off()
        
    elif var == 2:
        red_led.off()
        blue_led.on()
        green_led.off()

    else:
        red_led.off()
        blue_led.off()
        green_led.on()

def close():
    GPIO.cleanup()
    win.destroy()

## WIDGETS
redButton = Radiobutton(win, text = 'RED LIGHT', font=myFont,variable = val, val = 1, command= ledToggle, bg= 'red', height= 2, width= 30)
redButton.grid(row=0,column=1)

blueButton = Radiobutton(win, text = 'BLUE LIGHT', font=myFont, variable = val, val = 2, command= ledToggle, bg= 'blue', height= 2, width= 30)
blueButton.grid(row=1,column=1)

greenButton = Radiobutton(win, text = 'GREEN LIGHT', font=myFont, variable = val, val = 3, command= ledToggle, bg= 'green', height= 2, width= 30)
greenButton.grid(row=2,column=1)

exitButton = Radiobutton(win, text = 'EXIT', font=myFont, command= close, bg= 'yellow', height= 2, width= 10)
exitButton.grid(row=3 , column= 1)

win.mainloop()