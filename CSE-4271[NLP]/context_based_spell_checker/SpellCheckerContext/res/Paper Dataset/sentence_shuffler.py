
import random

f = open("spell_checker_dataset_bellayetbot", "r")
lines = f.readlines()
f.close()

f = open("spell_checker_dataset_bellayetbot_1k", "w")

flag = dict()

for i in range(0, len(lines)):
    flag[i] = 0

counter = 0
while (counter <= 500):
    v = random.randint(0, len(lines)/2-1)  # from 0,1,2,......, len(lines)/2-1
    print v
    if(flag[v] == 0):
        counter = counter+1
        f.write(lines[v*2])
        f.write(lines[v*2+1])
