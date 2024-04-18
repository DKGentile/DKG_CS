'''
    Demitri Gentile
    SHEDH.py
    3/10/22
    Version 1.3
    This program will create a .txt file named 'golf',
    at first it will ask the user how many golfers they
    would like to record, then the program will ask for
    the golfer's name and score, then it will display the
    name and score of each golfer.
'''
#creating golf.txt
w6=open('golf.txt','w')
w6.close()
def main():
    #asking the user how many golfers they would like to record
    a=int(input('How many players would you like to record scores for?: '))
    b=1
    #creating a loop that will ask for the appropiate amount of golfer's information
    while b<=a:
        #opening golf.txt for appending
        w6=open('golf.txt','a')
        #'b' is being used as a way to record each golfer
        b=str(b)
        w6.write('Golfer '+b+':'+'\n')
        #asking for golfer's name
        name=input('What is your name?: ')
        #converting the name to a string, so it can be written
        name=str(name)
        #writing the golfer's name
        w6.write(name+'\n')
        #asking for golfer's score
        score=int(input('What was your score?: '))
        #converting the score into a string so it can be written
        score=str(score)
        w6.write(score+'\n')
        w6.close()
        #converting 'b' back to an integer so it can be used in the loop
        b=int(b)
        b=b+1
    read()

def read():
    #opening golf.txt
    w6=open('golf.txt','r')
    desc=w6.read()
    print('===================================================')
    #printing the file's contents
    print(desc)
    w6.close

main()
