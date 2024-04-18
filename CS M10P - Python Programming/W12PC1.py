'''
    Demitri Gentile
    5/8/2022
    W12PC1.py
    V1.0
    This program will ask for the name, breed, and age of
    the user's animal, and then feed the information back
    to them through the 'Pets' class within the W12PC
    module.
'''
import W12PC
name=str(input("What is the animal's name?: ")) #getting the name input
breed=str(input("What breed is the animal?: ")) #getting the breed input
age=str(input("How old is the animal?: ")) #getting the animal input (all from user)
pets=W12PC.Pet(name,breed,age) #feeding these three parameters into the 'Pet' class
print('You entered:')
print(pets.getName(),'who is a',pets.getAnimalType(),'that is',pets.getAge(),'years old') #retrieving the information assigned to the 'Pet' class

