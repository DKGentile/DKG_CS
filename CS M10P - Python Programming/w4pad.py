#Week 4, Pennies for Pay
'''
    Demitri Gentile
    w4tag22.py
    2/7/2022
    Version: 1.2
    The following program will calculate how much
    money the user will have if their money doubled
    every day, after a given time, starting with a
    single penny on the first day.
'''
#Informing the user of the program's intent
print('Suppose every day your money magically doubled, but you had start with a single penny.')
#Asking the user for how many days they will be doubling their money
d=int(input('How many days will you be waiting?: '))
#Data validation, making sure the user enters a value between 1 and 64
while d<1 or d>64:
    print('Sorry, please enter a value between 1 and 64.')
    d=int(input('How many days will you be waiting?: '))
j=1 #establishing a base value for day 1
while d>=1 and d<=64 and j<=d:
    s=(2**(j-1))*0.01 #formula; 2**0=1, 2**1=2, 2**2=4, etc. Product is multiplied by 0.01 to represent pennies.
    print('On day,',j,',you will have $',format(s,'0.2f')) #printing the result, the amount of pennies is rounded to the hundredths place, representing a dollar value.
    j+=1 #"j" will increase and loop untill j=d

#"j" is set to 1, representing the amount of days that have passed.
#"j" will increase in value, representing the amount of days that have passed, up until j=d(days that the user wants to calculate).
