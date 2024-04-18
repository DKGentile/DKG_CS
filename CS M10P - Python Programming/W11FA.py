'''
    Demitri Gentile
    W11FA.py
    4/25/2022
    V1.1
    The following program will read text from two files,
    it will then strip all non-letter characters(commas, periods,
    new spaces, etc.), then it will convert the string to all
    lower case (so that the set will not repeat words due to
    different capitalizations of the same word), and finally
    the string will be converted into a set.
    The same process will occur to the second text, then the program
    will display the unions, intersections, differences, etc. between
    the two sets.

'''
#opening the first file
w=open('text1.txt','r')
#reading the whole file and creating a string
r=w.read()
#removing all non-letters from the string
r=r.strip('\n')
r=r.replace('.','')
r=r.replace(',','')
r=r.replace('"','')
r=r.replace("'",'')
#making all words lowercase, to prevent repitition of the same word with different capitalizaitons
r=r.lower()
#making 't1' into a list where every element is a word from the string
t1=r.split()
#making 't1' a set so it only contains unique elements
t1=set(t1)
w.close()

#same method as the first document
w=open('text2.txt','r')
r=w.read()
r=r.strip('\n')
r=r.replace('.','')
r=r.replace(',','')
r=r.replace('"','')
r=r.replace("'",'')
r=r.lower()
t2=r.split()
t2=set(t2)
w.close()

#forming a union between t1 and t2 to show the unique words from both texts
print('The unique words from BOTH files were: ',t1.union(t2))
print('=================================================================')

#showing an intersection between the two lists to show the unique words they share
print('The unique words that BOTH files SHARED were: ',t1.intersection(t2))
print('=================================================================')

#showing the unique words from the first that are not in the second
print('The unique words from the FIRST text that are NOT in the second were: ',t1.difference(t2))
print('=================================================================')

#showing the unique words from the second that are not in the first
print('The unique words from the SECOND text that are NOT in the first were: ',t2.difference(t1))
print('=================================================================')

#showing the unique words that neither set shared
print('The unique words that NEITHER set shared were: ',t1^t2)
print('=================================================================')
