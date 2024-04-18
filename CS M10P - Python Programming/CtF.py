#Week 3 Homework, Celsius to Fahrenheit temperature converter
'''
    Demitri Gentile
    CtoF.py
    1/25/2022
    Version: 1.0
    This program will convert a given temperature from Celsius ("c") to Fahrenheit ("f")
    by using the proper formula to do so. The program will also run data validation in
    order to correct the user and request a valid input.
'''
#Input
c=int(input('What tempurature,in Celsius, would you like converted to Fahrenheit(between -60C and 200C)?'))
while c>200 or c<-60: #Data Validation
    print('Sorry, invalid value. Please enter a number between -60 and 200')
    c=int(input('Enter your tempurature: ')) #Requesting a new valid input
if -60<c<200: #if statement for proper calculation
    f=(9/5)*c+32
    print(f,'Fahrenheit')
