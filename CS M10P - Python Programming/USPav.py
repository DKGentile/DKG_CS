'''
    Demitri Gentile
    USPav.py
    v1.4
    3/15/2022
    The following program will open USPopulation.txt, a file that already
    has information stored on it, then it will calculate the average growth
    between the numbers and store it onto a filed named USPav.txt.
    The program will then proceed to calculate the average growth of the given
    numbers, and will inform the user of when the greatest increase, and least
    greatest increase was.
'''
#creating a file to store the growth between years
h6=open('USPav.txt','w')
h6.close
w7=open('USPopulation.txt','r')
line=w7.readline()
h=line
while h!='':
    z=w7.readline()
    if z=='':
        break
    else:
        z=float(z)
        h=float(h)
        av=z/h
        av=av-1
        format(av,'0.3f')
        av=str(av)
        h6=open('USPav.txt','a')
        h6.write(av+'\n')
        h6.close
        h=z
t5=open('USPav.txt','r')
b=0
while t5!='':
    z=t5.readline()
    if z=='':
        break
    b+=1
h6.close
h6=open('USPav.txt','r')
j=0
l=0
while h6!='':
    k=h6.readline()
    if k=='':
        break
    k=float(k)
    j=j+k
    l=l+1
n=j/l
n=n*100
print('The average annual population increase of the United States, from 1950 to 1990, was:',(format(n,'0.2f')+'%'))
h6.close
h6=open('USPav.txt','r')
grt=0
lst=10
year=1953
fyear=1951
while line!='':
    a=h6.readline()
    b=h6.readline()    
    if a=='' and b=='':
        break
    else:
        a=float(a)
        b=float(b)
        if a>b:
            fgrt=a
            flst=b
            if fgrt>grt:
                grt=fgrt
                gyear=year
            else:
                pass
            if flst<lst:
                lst=flst
                Lyear=fyear
            else:
                pass
        elif b>a:
            fgrt=b
            flst=a
            if fgrt>grt:
                grt=fgrt
                gyear=fyear
            else:
                pass
            if flst<lst:
                lst=flst
                Lyear=year
            else:
                pass
    year=year+1
    fyear=fyear+1

grt=grt*100
lst=lst*100
print('============================================================================================')
print('The greatest year of population growth was:',gyear,', with a population growth of',format(grt,'0.2f')+'%')
print('The year of least population growth was:',Lyear,', with a population growth of',format(lst,'0.2f')+'%')
print('========================================================================================')
