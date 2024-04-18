'''
    Demitri Gentile
    W12CC.py
    5/5/2022
    V1.0
    The following set of code for
    a class named 'Car'. This car
    has make, model, and speed as
    attributes that can also be
    called upon by another
    program.
'''
class Car:
    def __init__(self,year,make,speed):
        self.__year_model=year
        self.__make=make
        self.__speed=speed
    def setSpeed(self,s):
        s=0
        self.__speed=s
    def accelerate(self):
        self.__speed+=5
        return(self.__speed)
    def braek(self):
        self.__speed-=5
        return(self.__speed)
    def getSpeed(self):
        return(self.__speed)
    def getMake(self):
        return self.__make
    def getYear(self):
        return(self.__year_model)
        
        
    
    
        
