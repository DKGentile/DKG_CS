'''
    Demitri Gentile
    primenum.py
    2/21/22
    Version: 1.6
    the program will ask the user for a number
    and tell whether or not it is prime.
'''
print('''The following program will determine whether or not the number you have entered is considered prime.
=====================''')
def isPrime():#defining function
    p=int(input('Please enter a number greater than 5: '))#asking the user for an input
    while p<=5:
        print('Sorry, invalid entry.')
        p=int(input('Please enter a number greater than 5: '))
    for k in range(2, p//2):#sets 'k' to a number between 2 and the remainder of p/2
        if (p%k)==0: #if p/k does NOT produce a remainder, then the number is NOT prime, for it can be evenly divided.
            print(p,'is not a prime number')
            break
        else: #if p/k does produce a remainder, then it can not evenly divide, which means the number IS prime
            print(p,'is prime!')
            break

isPrime()
