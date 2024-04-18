'''
    Demitri Gentile
    5/6/2022
    W12CC1.py
    V1.1
    The following program will import
    W12CC.py and use the class 'car'
    to accelerate and then break the
    car five times.
'''

import W12CC #importing W12CC
myYear=str(input('When was the car made?: ')) #setting the year of the car
myMake=str(input('What is the make and model of the car?: ')) #setting the make of the car
mcr=W12CC.Car(myYear,myMake,0) #calling upon the class within the module
a=1 #setting a counter so the 'accelerate' function is only called five times
while a<=5:
    mcr.accelerate() #calling upon the accelerate function within the class defined by mcr
    print('You are moving at',mcr.getSpeed(),'mph') #informing the user of the speed
    a=a+1 #adding 1 to the counter
a=1 #resetting the counter
while a<=5 and mcr.getSpeed()>0:
    mcr.braek() #calling upon the 'braek' function within the Car class
    print('You are moving at',mcr.getSpeed(),'mph') #informing the user of their speed
    a=a+1 #adding 1 to the counter
if mcr.getSpeed()==0: #if the getSpeed value is 0, the program will inform the user that the car is parked
    print('Your',mcr.getYear(),mcr.getMake(),'is now parked.')
else: #if the getSpeed value is greater than 0, the program will inform the user the speed they have left it going
    print('Your',mcr.getYear(),mcr.getMake(),'is moving at',mcr.getSpeed(),'mph')
input()

