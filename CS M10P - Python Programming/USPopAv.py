'''
    Demitri Gentile
    USPopAv.py
    3/15/2022
    Version 1.2
    This program will read through USPopulation.txt
    and give an average annual population growth. Then
    the program will print which year saw the greatest US
    population growth, and which year saw the least
    population growth.
'''
#opening USPopulation.txt
w6=open('USPopulation.txt','r')
#creating a file to store each year's population increase
t6=open('USPopav22.txt','w')
t6.close
#creating variables to use in calculation later
sav=0
yc=0
#reading each line of USPopulation.txt
a=w6.readline()
b=w6.readline()
#creating a loop to calculate each year's annual growth,
#then the loop will record this information to USPopav22.txt,
#then the loop will increase 'yc' by one, to keep track of how many years are being observed
while a!='' and b!='':
    a=int(a)
    b=int(b)
    c=b-a
    sav=sav+c
    c=str(c)
    t6=open('USPopav22.txt','a')
    t6.write(c+'\n')
    t6.close
    yc=yc+1
    a=w6.readline()
    b=w6.readline()
#'mav' is the average annual increase over the span of these 40 years
#'sav', the sum of all the growth, is divided by 'yc', the number of years observed, in order to calculate an average yearly growth
mav=sav/yc
#'mav' is multiplied by a thousand because the information in USPopulation.txt was in thousands
mav=mav*1000
#informing the user of the average annual population increase
print('The average yearly increase in United States population from 1950 to 1990 was:',"{:,}".format(mav,'0.f'))
w6.close()
#opening USPopav22.txt to see which years saw the greatest and least growth
f6=open('USPopav22.txt','r')
a=f6.readline()
b=f6.readline()
#'ori' is the first year of population growth
ori=1951
#'yec' and 'fyec' is used to track the passing of time
yec=0
fyec=1
#'gor' is used to keep track of the greatest year
gor=0
#'lor' is used to keep track of the least year
lor=999999
#the following loop will retrieve the annual growth by year from USPopav22.txt,
#the loop will then figure out both the largest and least increase, and assign a year to them
while a!='' or b!='':
    a=float(a)
    b=float(b)
    if a>b:
        store=a
        if store>gor:
            gor=store
            gyear=ori+yec
        else:
            pass
    elif b>a:
        store=b
        if store>gor:
            gor=store
            gyear=ori+fyec
        else:
            pass
    if a<b:
        store=a
        if store<lor:
            lor=store
            Lyear=ori+yec
        else:
            pass
    elif b<a:
        store=b
        if store<lor:
            lor=store
            Lyear=ori+fyec
        else:
            pass
    yec=yec+4
    fyec=fyec+4
    a=f6.readline()
    if a=='':
        break
    b=f6.readline()
    if b=='':
        break

print('The year with the greatest increase was:',gyear)
print('The year with the least greatest increase was:',Lyear)
    
