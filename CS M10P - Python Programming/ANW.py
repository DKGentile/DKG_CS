'''
    Demitri Gentile
    ANW.py
    4/18/2022
    V.1
    This program will read text.txt and inform the
    user the average words for every sentence read.
'''
#creating a blank list to store the amount of words per sentence
av=[]
#creating variable 'c' to store the amount of sentences read
c=0
#opening and reading text.txt
w10=open('text.txt','r')
#reading the first line of text.txt
a=w10.readline()
#the following loop will split every word from the sentence and store it in a list
#then the loop will count the amount of words (objects) within the list
#finally, the numerical value for the amount of words per sentence will be stored into the list 'av'
while a!='':
    x=a.split()
    av.append(len(x))
    c=c+1
    a=w10.readline()
#adding up the amount of words from every sentence
y=sum(av)
#dividing the amount of words counted (y) by the amount of sentences counted (c) in order to get the average amount of words per sentence
av=y/c
#formating the average amount of words per sentence
f=format(av,'0.0f')
#informing the user of the amount of words per sentence
print('The average amount of words per sentence was',f,'words.')
