'''
    Demitri Gentile
    W12CC2.py
    5.7.2022
    V1.6
    This program is functionally similar to W12CC1.
    The reason this program was created was because
    I misinterpreted what the assignment was asking.
    As mentioned, this program is the same as W12CC1,
    the only difference being that this program allows
    the user to accelerate and break the car as they please.
'''
import W12CC

myYear=str(input('When was the car made?: '))
myMake=str(input('What is the make and model of the car?: '))
mcr=W12CC.Car(myYear,myMake,0)
q=str(input('Would you like to accelerate?[y/n]: '))
q=q.capitalize()
while q=='Y':
    mcr.accelerate()
    print('You are moving at',mcr.getSpeed(),'mph')
    q=str(input('Would you like to keep accelerate?[y/n]: '))
    q=q.capitalize()
q=str(input('Would you like to break?[y/n]: '))
q=q.capitalize()
while q=='Y' and mcr.getSpeed()>0:
    mcr.braek()
    print('You are moving at',mcr.getSpeed(),'mph')
    q=str(input('Would you like to break?[y/n]: '))
    q=q.capitalize()
if mcr.getSpeed()==0:
    print('Your',mcr.getYear(),mcr.getMake(),'is now parked.')
else:
    print('Your',mcr.getYear(),mcr.getMake(),'is moving at',mcr.getSpeed(),'mph')

input()

