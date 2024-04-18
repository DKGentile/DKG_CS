#Week 3 Lab#1 Body Mass Index
'''
    Demitri Gentile
    BMI.py
    1/31/2022
    Version: 1.0
    This program will calculate Body Mass Index.
    First, it will ask the user for their weight,
    in pounds, then the program will ask for their
    height, in inches. The program will then calculate
    their BMI, and tell the user whether or not they
    are considered underweight, overweight, or at an
    optimal weight.
'''
print('This is a Body Mass Index calculator.')#informing the user the program's meaning
weight=int(input('Please enter your weight, in pounds(lbs): '))#asking the user for their weight
height=int(input('Please enter your height, in inches: '))#asking the user for their height
bmi=(weight*703)/height**2 #calculating the user's BMI
print(format(bmi,'.1f'),'''is your BMI''')#informing the user of their BMI, which is rounded to the tenth's place
#the following if-elif is determening which catagory of body mass the user falls into
if bmi>25:
    print('Your BMI is considered overweight.')
elif 18.5<bmi<25:
    print('Your BMI is considered optimal.')
elif bmi<18.5:
    print('Your BMI is considered underweight.')
