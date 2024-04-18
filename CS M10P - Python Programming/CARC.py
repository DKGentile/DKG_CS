'''
    Demitri Gentile
    5/2/2022
    V 1.0
    CARC.py
    This program will create a class "Rectangle" that will then
    be used by the 'main' function in order to inform the user
    the area and perimiter of the two values they entered/
'''

class Rectangle:
    def __init__(self,ln,w):
        self.__length=ln
        self.__width=w
    def setLength(self,l):
        self.__length=l
    def setWidth(self,w):
        self.__width=w
    def getLength(self):
        return(self.__length)
    def getWidth(self):
        return(self.__width)
    def getArea(self):
        return(self.__length*self.__width)
    def getPerim(self):
        return(self.__length*2+self.__width*2)

def main():
    mylength=float(input('What is the length?: '))
    mywidth=float(input('What is the width?: '))
    rect1=Rectangle(mylength,mywidth)
    print('The area is: ',rect1.getArea())
    print('The perimiter is: ',rect1.getPerim())

main()
