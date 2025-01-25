import math
'''

Newtons Method is as follows:

P1 = P0 - f(P0)/f'(P0)

'''

def F(x):
    return x*math.sin(math.sqrt(x))

def dF(x):
    return math.sin(math.sqrt(x)) + ( (x * math.cos(math.sqrt(x)) ) / (2*math.sqrt(x)) )

def nmeth(x, z=1):
    y=x-(F(x)/dF(x))
    print(x,y,z)
    print("==========")
    print(F(y))
    print("\n")
    if(z<30):
        nmeth(y,z+1)

