"""
Code to process the molecular biology dataset 
"""
filename="moleculer biology"
f=open(filename,"r")
lines = f.readlines()
f.close()

f=open("train.txt","w")

for i in lines:
    temp=i.split()
    label=temp[0].split(',') 
    sentence=""
    
    for j in range(0,len(temp[2])):
        char = temp[2][j]
        if(sentence==""):
            sentence=char
        else:
            sentence=sentence+','+char
    sentence=sentence+","+label[0]
    f.write(sentence+'\n') 
f.close() 

