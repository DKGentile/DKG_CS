'''
    Demitri Gentile
    W8DEXAM.py
    3/21/2022
    Version 1.1
    This program will read student_solution.txt and determine
    the amount of "answers" that are correct.
    The program will then inform the user whether or not they
    have passed or failed the exam, the amount of questions they got wrong,
    the numbers of the questions they got wrong, and the percentage of their
    score.
'''
#opening student_solution.txt for reading
w6=open('student_solution.txt','r')
#creating a list of the correct answers
correct=['B','D','A','A','C','A','B','A','C','D','B','C','D','A','D','C','C','B','D','A',]
#creating a list that will fill itself with the answers from student_solution.txt
usr=[]
#reading the first line of student_solution.txt
inpt=w6.readline()
#striping the \n (new line) from the end of each answer
inpt=inpt.strip('\n')
#creating a loop that will append every answer from student_solution.txt and insert each string into the "usr" list
while inpt!='':
    usr.append(inpt)
    inpt=w6.readline()
    inpt=inpt.strip('\n')
#'a' and 'b' will act as a way to navigate throughout each list
#'a'=1,'b'=1, usr[0:1], correct[0:1] etc.
a=0
b=1
count=0
inc=[]
#the following loop will determine the amount of incorrect answers append the 'inc' list with the numbers of the questions answered incorrectly 
while b<=20:
    #if correct[x]=usr[x], no need for further action
    if correct[a:b]==usr[a:b]:
        pass
    #if correct[x]!=usr[x], append 'b' (the number of the question) to the 'inc' list
    #if correct[x]!=usr[x], add 1 to 'count' to keep track of the total amount of incorrect answers
    else:
        inc.append(b)
        count=count+1
    #b+=1 & a+=1 to move along the 'correct' and 'usr' lists
    b=b+1
    a=a+1
#'perc' being used to determine the percentage value grade of the answers from student_solution.txt
perc=20-count
perc=perc/20
#informing the user whether or not they passed
#informing the user of the total amount of questions they got wrong
#informing the user the numbers of the questions they got wrong
if count>=15:
    print('Congradulations, you passed! You got',count,'questions wrong, they were:',inc[:])
else:
    print('Sorry, you failed. You got',count,'questions wrong, they were:',inc[:])
#informing the user their grade on the exam
print('Your final grade was:',(format(perc,'.2%')))
