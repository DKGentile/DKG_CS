'''
    Demitri Gentile
    morty.py
    2/21/22
    Version: 1.2
    This program will calculate a mortgage, and ask the user for the variables
    related.
'''
def mortgage():#function that will gather information
    p=int(input('How much money would you like to loan? ')) #asking for amount
    while p>1000000 or p<100000: #input validation
        print('Sorry, invalid amount.')
        p=int(input('Please enter an amount between $100,000 and #1,000,000: '))
    if p<=1000000 or p>=100000:
        term=int(input('For how many years will you be paying this loan? '))#asking for mortgage length
        while term<0: #input validation
            print('Sorry, invalid entry.')
            term=int(input('Please enter a positive number: '))
        rate=int(input('What is the interest rate on the loan? ')) #asking for mortgage interest rate
        while rate<0: #input validation
            print('Sorry, invalid entry.')
            rate=int(input('Please enter a positive number: '))
    calc(p,rate,term)
    
def calc(p,rate,term): #function that will calculate monthly mortgage rate
    term=term*12
    rate=rate/1200
    yp=(p*rate)/(1-(rate+1)**(-term))
    print('Your monthly mortgage payment will be ',format(yp,'0.2f'),sep='$')


mortgage()
    

