'''
    Demitri Gentile
    W10SC.py
    4/18/2022
    V1.2
    The following program consists of two functions.
    The program will define a function that will be used
    to capitalize the first letter of every sentence.
    Then the program will ask the user for an imput.
    Finally, the program will feed the user's input into
    the fucntion where it will be capitalized properly.
'''
#defining 'cap', which is the function used to capitalize the sentences.
def cap(usr):
    #stripping all empty spaces from the user's input
    usr=usr.strip()
    #splitting the input into sentences which are defined by the period marking the end of one.
    y=usr.split('.')
    #creating a for loop that will capitalize all the sentences (which have been split into elements of a list)
    for x in y:
        if x!='':
            x=x.strip()
            #adding a period and space between each sentence so as to keep propper formatting
            print(x.capitalize(),end='. ')
#asking the user for an input
usr=str(input('Enter a sentence with improper capitalization: '))
#calling on the 'cap' function and passing the user's input (usr) into it.
cap(usr)


