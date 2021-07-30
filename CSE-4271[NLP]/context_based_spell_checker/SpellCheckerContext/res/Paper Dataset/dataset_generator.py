# dataset 3: vasha shikkha and somewhere in data

import random

# reading lines
f = open("dataset2.txt", "r")
line = f.readlines()
f.close()


# reading words from domain vasha shikkha / somwhere in data
correct_wrong_word_map = dict()


def read_word_map(filename):
    o = open(filename, "r")
    save = o.readlines()
    for i in save:
        print "i = ", i, " ", len(correct_wrong_word_map)
        l = i.split()
        print l[0], l[1], l[2]
        wrong = l[0]
        correct = l[2]
        correct_wrong_word_map[correct] = wrong
    o.close()


# "SomewhereInData.txt"
# file name 1: bellayetbot.txt
# file name 2: SomewhereInData.txt
read_word_map("SomewhereInData.txt")


def make_error_sentence(sentence):
    word_list = sentence.split()
    flag = dict()
    for i in range(0, len(word_list)):
        flag[i] = 0
    counter = 0
    while True:
        random_idx = random.randint(0, len(word_list)-1)
        #print random_idx," ",counter
        word = word_list[random_idx]
        if(word in correct_wrong_word_map):
            break
        else:
            if(flag[random_idx] == 0):
                counter = counter+1
                flag[random_idx] = 1
            if(counter >= len(word_list)):
                return ""
    word_list[random_idx] = correct_wrong_word_map[word_list[random_idx]]
    res = ""
    for i in word_list:
        if(res == ""):
            res = i
        else:
            res = res+" "+i
    return res


def make_sentence_from_word(word_list):
    res = ""
    for i in word_list:
        if(res == ""):
            res = i
        else:
            res = res+" "+i
    return res


f = open("spell_checker_dataset_somewhereindata", "w")

guni = 0
for i in line:
    guni = guni+1
    print "processed ", guni
    if(i == '\n'):
        continue
    error = make_error_sentence(i)
    if(error != ""):
        real = make_sentence_from_word(i.split())
        f.write(real+'\n')
        f.write(error+'\n')
f.close()
