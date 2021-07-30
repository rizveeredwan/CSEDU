#!/usr/bin/env python
# -*- coding: utf-8 -*-

import random 

#dataset1 making section 
""""
f=open("dataset1.txt","r")
line = f.readlines()
f.close()

f=open("dataset2.txt","w")
cnt=0
for i in line:
    temp=i.split(' ')
    if(len(temp)>1):
        string = ""
        prev = ""
        for j in temp:
            if(len(j) == 0):
                continue
            if(string == ""):
                string = j 
                prev = j
            else:
                if(prev == "\n" and j == "\n"):
                    continue
                string = string + " " + j 
                prev = j
        f.write(string)  
        cnt=cnt+1
f.close()  
""" 

#dataset 2: Sentence Error making code 
f=open("dataset2.txt","r")
line = f.readlines()
f.close() 


"""
Reading psg.txt file 
making group_characters 
"""
f=open("psg.txt","r")
characters = f.readlines()
group_characters = [] 
temp_list = [] 
for i in characters:
    if(i != '#\n'):
        value = i.split('\n') 
        temp_list.append(value[0]) 
    else:
        group_characters.append(temp_list)
        temp_list=[] 
f.close()

"""
reading correct words 
"""
correct_words = [] 

f=open("dict.txt","r")
correct_words = f.readlines() 
for i in range(0,len(correct_words)):
    temp = correct_words[i] 
    temp = temp.split('\n')
    correct_words[i]=temp[0]  


""" 
function to make error sentence
""" 

def choose_same_group_symbol(symbol):
    global group_characters
    save = [] 
    found = False
    for i in group_characters: #getting list 
        for j in i: #traversing in the list 
            #print type(j.decode('utf-8'))," ",type(symbol)
            if(j.decode('utf-8') ==symbol):
                found=True  
                save = i
                break
        if(found == True):
            break 
    if(len(save) == 1):
        return save[0] 
    elif(len(save)>1):
        while True:
            pos = random.randint(0,len(save)-1)
            if(save[pos].decode('utf-8') == symbol):
                continue
            else:
                return save[pos] 
    else:
        return group_characters[0][0] 
         

def make_error_sentence(sentence):
    word_list = sentence.split(' ')
    flag = dict() 
    for i in range(0,len(word_list)):
        flag[i]=0 
    while True:
        random_idx = random.randint(0,len(word_list)-1)
        word = word_list[random_idx]
        temp=word.split('\n')
        if(temp[0] in correct_words):
            #print "YES"
            break 
        else:
            go=False
            if(flag[random_idx] == 0):
                flag[random_idx]=1
            for i in range(0,len(word_list)):
                if(flag[i] == 0):
                    go=True
                    break 
            if(go==False):
                return sentence 

    random_idx = random.randint(0,len(word_list)-1)
    word = word_list[random_idx] 
    random_word_pos = "" 
    v=""
    if(random_idx == len(word_list)-1):
        #ending word 
        word = word.decode('utf-8')
        random_word_pos = random.randint(0,max(0,len(word)-2))  
    else:
        word = word.decode('utf-8')
        random_word_pos = random.randint(0,len(word)-1)
    v = choose_same_group_symbol(word[random_word_pos])
    new_word=""
    #print word[random_word_pos]," ",v
    for j in range(0,len(word)):
        if(j == 0):
            if(j == random_word_pos):
                new_word = v  
            else:
                new_word = word[j].encode('utf-8') 
        else:
            if(j == random_word_pos):
                new_word = new_word + v 
            else:
                new_word = new_word +word[j].encode('utf-8')  
    
    word_list[random_idx] = new_word 
    result = ""
    for i in word_list:
        if(result==""):
            result = i 
        else:
            result=result+" "+i
    return result 


def distance(sen1,sen2):
    t1=sen1.decode('utf-8')
    t2=sen2.decode('utf-8')
    if(len(t1) != len(t2)):
        return False
    return True


def all_word_in_dict(sentence):
    temp = sentence.split(' ')
    for i in temp:
        if(i not in correct_words):
            return False
    return True 

"""
word = 'আমি খাবার খাই\n'
word = word.decode('utf-8') 
print len(word)
for i in range(0,len(word)):
    print i," ",word[i]
""" 
f=open("spell_checker_dataset2.txt","w") 
save_real=[]
save_error=[]
counter=0 
for i in line:

    
    if(i=='\n'):
        continue 
    real = i 
    error = make_error_sentence(real) 
    decision = distance(real,error)
    if(decision==False):
        print "Shit ",real," ",error
    else:
        save_real.append(real)
        save_error.append(error)
    counter=counter+1
    print "done ",counter

print len(save_real)," ",len(save_error)



for i in range(0,len(save_real)):
    s1 = save_real[i].split('\n')
    s2 = save_error[i].split('\n')  
    f.write(s1[0]+'\n')
    f.write(s2[0]+'\n') 

"""
s = make_error_sentence("আমি ভাত খাই\n")
print s
""" 
f.close()  
#print save
