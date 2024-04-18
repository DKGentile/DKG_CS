'''
    Demitri Gentile
    RANDRAAND.py
    v1.2
    3/15/2022
    This program will generate a random number then ask
    the user to guess the randomly generated number. The
    program can also be repeated, should the user desire
    to keep on playing. Every time the user guesses the
    correct number, the program will keep a score.
'''
#importing the random module
import random
#using 'd' as a global variable to store the user's score
d=0
#creating a function, necessary for repitition
def guess():
    #calling the global variable (to keep score)
    global d
    #generating the random number
    r=random.randint(1,101)
    while r==r:
        #asking the user to guess the number, 'r'
        try:
            gue=int(input('Guess my number, between 1-100: '))
        #making sure the user enters a correct value(base 10, etc.)
        except:
            gue=int(input('Please enter a whole number: '))
        #creating a loop so the user can continue guessing
        while gue!=r:
            while gue<r:
                print('Your Guess was too low!')
                gue=int(input('Please try again: '))
            while gue>r:
                print('Your guess was too high!')
                gue=int(input('Please try again: '))
            if gue==r:
                break
            break
        print('Congradulations! You guessed my number!')
        #using the global 'd' to keep score
        d=d+1
        print('You have guessed',d,'of my numbers.')
        #currently unsure how to creat an "y/n" string input
        ag=int(input('Would you like to play again [1=y/0=n]: '))
        if ag==1:
            #calling on another function that will simply replay the main function
            again()
        else:
            print('Thanks for playing!')
            break
        break

def again():
    guess()

guess()
