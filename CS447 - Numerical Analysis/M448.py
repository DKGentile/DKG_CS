import math

def bisecs(x,y):
    z=(x+y)/2
    a=EQ(x)
    b=EQ(y)
    c=EQ(z)
    
    if a<0.001 and a>0: 
        print(x)
        while True:
            z=0
    if b<0.001 and b>0: 
        print(y)
        while True:
            z=0
    if c<0.001 and c>0:
        print(z)
        while True:
            z=0

    if c<0 and a>0:
        print("p %10f left",z)
        print("[%10f,%10f]\n"%(x,z))
        return bisecs(x,z)
    if c<0 and b>0:
        print("p %10f right",z)
        print("[%10f,%10f]\n"%(y,z))
        return bisecs(y,z)
    if c>0 and a<0:
        print("p %10f left",z)
        print("[%10f,%10f]\n"%(z,x))
        return bisecs(z,x)
    if c>0 and b<0:
        print("p %10f right",z)
        print("[%10f,%10f]\n"%(z,y))
        return bisecs(z,y)
    
def EQ(x):
    return (x+2)*(x+1)*x*((x-1)**3)*(x-2)


        
    


