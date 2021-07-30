import random


n=10000
x=[]
y=[]
i=0
f=open("input_3.txt","w")
while(i<=10000):
    v=random.randint(0,10000000)
    u=random.randint(0,100000000)
    i=i+1
    f.write(str(v)+" "+str(u)+"\n")
f.close()




