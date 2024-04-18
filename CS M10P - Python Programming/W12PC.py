'''
    Demitri Gentile
    5/8/2022
    W12PC.py
    V1.2
    The following module contains a class 'Pet'
    that is an object with the attributes 'name',
    'breed','age', all of whom are assigned a
    method that can also be called upon.
'''

class Pet:
    def __init__(self,name,breed,age): #initializing the object's attributes
        self.__name=name
        self.__type=breed
        self.__age=age
    def setName(self,name):
        self.__name=name
    def setAnimalType(self,breed):
        self.__type=breed
    def setAge(self,age):
        self.__age=age
    def getName(self):
        return self.__name
    def getAnimalType(self):
        return self.__type
    def getAge(self):
        return self.__age
