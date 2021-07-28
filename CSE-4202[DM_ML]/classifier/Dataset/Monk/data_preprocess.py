"""
This file is to preprocess data of Monk 
"""
filename="monk"
f=open(filename,"r")
lines=f.readlines() 
f.close() 

f=open("train.txt","w")

for i in lines:
    temp=i.split()
    sentence=""
    for j in range(1,len(temp)-1):
        if(sentence == ""):
            sentence=temp[j]
        else:
            sentence=sentence+","+temp[j] 
    sentence=sentence+','+temp[0] 
    f.write(sentence+'\n')
f.close()