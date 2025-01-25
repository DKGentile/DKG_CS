import math

def SF(x):
    return math.pow(math.e,-x**2)-2*x

def SM(x,y):
    try:
        z=((x*SF(y)-y*(SF(x)))/(SF(y)-SF(x)))
        print(z)
        SM(y,z)
    except:
        print("Error (Probably Divide by 0)")

