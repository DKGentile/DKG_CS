'''
    Demitri Gentile
    RN&F.py
    3/10/22
    Version 1.6
    This program will ask the user how many numbers they would like to generate.
    The program will than generate any number between 1-100 in the quantity that
    the user defines. Then, the program will will inform the user of the random
    numbers that have been generated, followed by a sum of all the numbers.
'''
#importing 'random' to allow random number generation
import random
#defining a function
def main():
    #opening and creating a file
    w6=open('W6HWRN.txt','w')
    #asking the user how many numbers they would like to generate
    a=int(input('How many random numbers would you like to generate?: '))
    #using 'b' as an integer to add on to
    b=0
    #creating a loop to generate enough numbers ('a' being the amount of numbers desired by the user)
    while b<=a:
        #generating a random integer between 1-100
        n=random.randint(1,101)
        #translating 'n' into a string, so it can be added to the .txt file
        n=str(n)
        #opening the text file created, 'a' being used to add onto the file and not overwrite it
        w6=open('W6HWRN.txt','a')
        #adding 'n' to the file, along with an open line
        w6.write(n+'\n')
        w6.close
        #adding onto b untill it is equal to 'a', the user's desired amount, when it will then break the loop
        b=b+1
    sec()

def sec():
    #opening the file
    w6=open('W6HWRN.txt','r')
    #assigning a value to the sting value of the text from the file
    allnum=w6.read()
    #informing the user of their randomly generated numbers
    print('Your random numbers are: '+'\n'+allnum+'\n','==========================================================')
    w6.close
    w6=open('W6HWRN.txt','r')
    #creating an integer to have a value added to it
    h=0
    #reading the first line of the text file, which would countain the first random number
    line=w6.readline()
    #creating a loop to read each line of the file untill there is a blank
    while line != '':
        #translating the line value into an integer
        z=int(line)
        #adding the values together
        h+=z
        #reading the next line, will continue the loop untill there are no more numbers
        line=w6.readline()
    print('The sum of all of your randomly generated numbers is:',h)

main()
