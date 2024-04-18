'''
    Demitri Gentile
    W4TAG.py
    2/7/2022
    Version: 1.0
    The system will ask the user to enter four test scores,
    then calculate the average of said scores. The system
    will repeat these questions five times, in respect to the
    five different students.
'''
#informing the user of the program's intent
print('''The following program will determine the average test scores for five students
==============================================================================''')
#asking for the user to enter the first test score
print('With respect to the first student, please enter the following.;')
#assigning a value to s1 (score 1)
s1=int(input('Enter the first test score: '))
#data validation (while loop), checking that the user entered a valid value between 0-100, and alowing a correction
while s1<0 or s1>100:
    print('Sorry, incorrect value. Test scores must be between 0 and 100')
    s1=int(input('Enter the first test score: '))
#assigning a value to s2 (score 2)
s2=int(input('Enter the second test score: '))
#data validation (while loop), checking that the user entered a valid value between 0-100, and alowing a correction
while s2<0 or s2>100:
    print('Sorry, incorrect value. Test scores must be between 0 and 100')
    s2=int(input('Enter the second test score: '))
#assigning a value to s3 (score 3)
s3=int(input('Enter the third test score: '))
#data validation (while loop), checking that the user entered a valid value between 0-100, and alowing a correction
while s3<0 or s3>100:
    print('Sorry, incorrect value. Test scores must be between 0 and 100')
    s3=int(input('Enter the third test score: '))
#assiging a value to s4 (score 4)
s4=int(input('Enter the fourth test score: '))
#data validation (while loop), checking that the user entered a valid value between 0-100, and alowing a correction
while s4<0 or s4>100:
    print('Sorry, incorrect value. Test scores must be between 0 and 100')
    s4=int(input('Enter the fourth test score: '))
#calculation of the average scores
av=(s1+s2+s3+s4)/4
if av>=90:
    print('The average test score of this student is',av,'which is an A!')
elif av>=80:
    print('The average test score of this student is',av,'which is a B!')
elif av>=70:
    print('The average test score of this student is',av,'which is a C.')
elif av>=60:
    print('The average test score of this student is',av,'which is a D.')
elif av<60:
    print('The average test score of this student is',av,'which is an F!')
#informing the user of the average score of the student
print('=========================================================================')
#repeat
print('With respect to the second student, please enter the following.')
s1=int(input('Enter the first test score: '))
while s1<0 or s1>100:
    print('Sorry, incorrect value. Test scores must be between 0 and 100')
    s1=int(input('Enter the first test score: '))
s2=int(input('Enter the second test score: '))
while s2<0 or s2>100:
    print('Sorry, incorrect value. Test scores must be between 0 and 100')
    s2=int(input('Enter the second test score: '))
s3=int(input('Enter the third test score: '))
while s3<0 or s3>100:
    print('Sorry, incorrect value. Test scores must be between 0 and 100')
    s3=int(input('Enter the third test score: '))
s4=int(input('Enter the fourth test score: '))
while s4<0 or s4>100:
    print('Sorry, incorrect value. Test scores must be between 0 and 100')
    s4=int(input('Enter the fourth test score: '))
av=(s1+s2+s3+s4)/4
if av>=90:
    print('The average test score of this student is',av,'which is an A!')
elif av>=80:
    print('The average test score of this student is',av,'which is a B!')
elif av>=70:
    print('The average test score of this student is',av,'which is a C.')
elif av>=60:
    print('The average test score of this student is',av,'which is a D.')
elif av<60:
    print('The average test score of this student is',av,'which is an F!')
print('=========================================================================')
#repeat
print('With respect to the third student, please enter the following.')
s1=int(input('Enter the first test score: '))
while s1<0 or s1>100:
    print('Sorry, incorrect value. Test scores must be between 0 and 100')
    s1=int(input('Enter the first test score: '))
s2=int(input('Enter the second test score: '))
while s2<0 or s2>100:
    print('Sorry, incorrect value. Test scores must be between 0 and 100')
    s2=int(input('Enter the second test score: '))
s3=int(input('Enter the third test score: '))
while s3<0 or s3>100:
    print('Sorry, incorrect value. Test scores must be between 0 and 100')
    s3=int(input('Enter the third test score: '))
s4=int(input('Enter the fourth test score: '))
while s4<0 or s4>100:
    print('Sorry, incorrect value. Test scores must be between 0 and 100')
    s4=int(input('Enter the fourth test score: '))
av=(s1+s2+s3+s4)/4
if av>=90:
    print('The average test score of this student is',av,'which is an A!')
elif av>=80:
    print('The average test score of this student is',av,'which is a B!')
elif av>=70:
    print('The average test score of this student is',av,'which is a C.')
elif av>=60:
    print('The average test score of this student is',av,'which is a D.')
elif av<60:
    print('The average test score of this student is',av,'which is an F!')
print('=========================================================================')
#repeat
print('With respect to the fourth student, please enter the following.')
s1=int(input('Enter the first test score: '))
while s1<0 or s1>100:
    print('Sorry, incorrect value. Test scores must be between 0 and 100')
    s1=int(input('Enter the first test score: '))
s2=int(input('Enter the second test score: '))
while s2<0 or s2>100:
    print('Sorry, incorrect value. Test scores must be between 0 and 100')
    s2=int(input('Enter the second test score: '))
s3=int(input('Enter the third test score: '))
while s3<0 or s3>100:
    print('Sorry, incorrect value. Test scores must be between 0 and 100')
    s3=int(input('Enter the third test score: '))
s4=int(input('Enter the fourth test score: '))
while s4<0 or s4>100:
    print('Sorry, incorrect value. Test scores must be between 0 and 100')
    s4=int(input('Enter the fourth test score: '))
av=(s1+s2+s3+s4)/4
if av>=90:
    print('The average test score of this student is',av,'which is an A!')
elif av>=80:
    print('The average test score of this student is',av,'which is a B!')
elif av>=70:
    print('The average test score of this student is',av,'which is a C.')
elif av>=60:
    print('The average test score of this student is',av,'which is a D.')
elif av<60:
    print('The average test score of this student is',av,'which is an F!')
print('=========================================================================')
#repeat
print('With respect to the fifth student, please enter the following.')
s1=int(input('Enter the first test score: '))
while s1<0 or s1>100:
    print('Sorry, incorrect value. Test scores must be between 0 and 100')
    s1=int(input('Enter the first test score: '))
s2=int(input('Enter the second test score: '))
while s2<0 or s2>100:
    print('Sorry, incorrect value. Test scores must be between 0 and 100')
    s2=int(input('Enter the second test score: '))
s3=int(input('Enter the third test score: '))
while s3<0 or s3>100:
    print('Sorry, incorrect value. Test scores must be between 0 and 100')
    s3=int(input('Enter the third test score: '))
s4=int(input('Enter the fourth test score: '))
while s4<0 or s4>100:
    print('Sorry, incorrect value. Test scores must be between 0 and 100')
    s4=int(input('Enter the fourth test score: '))
av=(s1+s2+s3+s4)/4
if av>=90:
    print('The average test score of this student is',av,'which is an A!')
elif av>=80:
    print('The average test score of this student is',av,'which is a B!')
elif av>=70:
    print('The average test score of this student is',av,'which is a C.')
elif av>=60:
    print('The average test score of this student is',av,'which is a D.')
elif av<60:
    print('The average test score of this student is',av,'which is an F!')
print('=========================================================================')
