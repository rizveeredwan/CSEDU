
f=open("bellayetbot.txt","r")
line = f.readlines()
f.close() 

save = line[1].split()
print save[0]
print save[1]
print save[2]