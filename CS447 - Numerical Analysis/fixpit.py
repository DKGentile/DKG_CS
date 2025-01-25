import math

def func(x):
    return 5/x**2+2

def it(x):
    return 1+1/x

def itmeth(x,p=0):
    y=it(x)
    if ((func(y)<0.00001 and func(y)>=0)or p>100):
        print(y)
        print(func(y))
        return y
    else:
        print("[x P]")
        print(y,p)
        print("f(Px)")
        print(func(y))
        print("=========================================================================")
        itmeth(y,p+1)