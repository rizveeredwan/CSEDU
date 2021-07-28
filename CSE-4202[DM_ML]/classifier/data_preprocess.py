#purpose of this file is to process data

filename="Dataset/Lymphograph/lymphograph"
f=open(filename,"r")
line=f.readlines() 
f.close()

class_col = int(input("Give the class row number(0 based index)"))
f=open("Dataset/Lymphograph/train.txt","w")

for i in line:
    single_row = i.split()
    elements = single_row[0].split(',')
    save = ""
    for i in range(0,len(elements)):
        if(i != class_col):
            if(save == ""):
                save=elements[i]
            else:
                save=save+","+elements[i]
    save=save+","+elements[class_col]
    f.write(save+'\n')
    print save
f.close() 
