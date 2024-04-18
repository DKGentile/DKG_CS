'''
    Demitri Gentile
    W9NS.py
    4/11/2022
    Version 1.2
    This program will read each line from both BoyNames.txt GirlNames.txt,
    and create a list for each .txt file read. The program will also convert
    each string into all capital letters, this will make sense later. Then, the
    program will ask the user for a boy's name AND a girl's name. Both of these
    inputs will be capitalized, so that a user mistake regarding capitalization
    of a letter will not output an incorrect response.
'''
#creating two empty lists, one for each gender being read
bn=[]
gn=[]
#the following two loops will read each line of the respective .txt file
#then the loop will strip the '\n' (new line) from the string
#then the loop will append the read string to the respective list
#finally, the loop will will capitalize all the letters of each string and repeat the loop
w9=open('BoyNames.txt','r')
a=w9.readline()
a=a.strip('\n')
while a!='':
    a=a.upper()
    bn.append(a)
    a=w9.readline()
    a=a.strip('\n')
w9.close()
w9=open('GirlNames.txt','r')
a=w9.readline()
a=a.strip('\n')
while a!='':
    a=a.upper()
    gn.append(a)
    a=w9.readline()
    a=a.strip('\n')
w9.close()
#the following will ask the user to input a boy's and girl's name
#then the user's input will be converted to a string, then that string will be capitalized
bame=str(input("What is the boy's name?: "))
bame=bame.upper()
game=str(input("What is the girl's name?: "))
game=game.upper()
#finally, the following two loops will determine wether or not the user's inputs are present in each list
if bame not in bn:
    print("Sorry, but the boy's name was NOT among the most popular boy's names between the years 2000 & 2009.")
else:
    print("Congradulations! You gave your son a generic name!")
if game not in gn:
    print("Sorry, but the girl's name was NOT among the most popular boy's names between the years 2000 & 2009.")
else:
    print("Congradulations! You gave your daughter a generic name!")
    
