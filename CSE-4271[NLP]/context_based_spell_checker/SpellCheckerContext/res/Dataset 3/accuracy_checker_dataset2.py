f=open("spell_checker_dataset3_2_output.txt","r")
lines = f.readlines()

def check_list(suggestion_list,target_line):
    counter=0
    for i in suggestion_list:
        counter=counter+1 
        save=i.split('\n')
        if(save[0] == target_line):
            return counter 
    return 100 #not found  

counter = 0
real_line = ""
error_line = ""
suggestion_list = [] 

freq=dict()
freq[1]=0
freq[3]=0
freq[5]=0
freq[10]=0
freq[-1]=0

total_sample=0

for i in lines:
    s=i 
    counter=counter+1
    if(counter == 3):
        continue
    if(counter == 1 or counter == 2):
        #got main line 
        line = s.split()
        save = ""
        for j in range(1,len(line)):
            if(save == ""):
                save = line[j]
            else:
                save=save+" "+line[j]
        if(counter == 1):
            real_line = save 
        elif(counter == 2):
            error_line = save 
    elif(counter<=13):
        suggestion_list.append(i)
        if(counter==13):
            counter=0
            idx=check_list(suggestion_list,real_line)
            if(idx==1):
                freq[1]=freq[1]+1 
            if(idx<4):
                freq[3]=freq[3]+1
            if(idx<6):
                freq[5]=freq[5]+1
            if(idx<11):
                freq[10]=freq[10]+1            
            if(idx==100):
                freq[-1] = freq[-1]+1 
            total_sample=total_sample+1 
            suggestion_list = []
            real_line = ""
            error_line = "" 

print "total sample = ",total_sample
print "top 1 percentage = ",(freq[1]*100.0)/(total_sample)
print "top 3 percentage = ",(freq[3]*100.0)/(total_sample)
print "top 5 percentage = ",(freq[5]*100.0)/(total_sample)
print "top 10 percentage = ",(freq[10]*100.0)/(total_sample)
print "top -1 percentage/Not found = ",(freq[-1]*100.0)/(total_sample)
