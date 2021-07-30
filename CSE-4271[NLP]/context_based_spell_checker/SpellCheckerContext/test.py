#!/usr/bin/python
# -*- coding: utf-8 -*-
import SpellChecker.suggestiongenerator as generator

# /home/rizvee/Books/4-2/NLP/Work/Dataset/kenlm/SpellCheckerContext /res


resfolder = '/home/rizvee/Books/4-2/NLP/Work/Dataset/kenlm/SpellCheckerContext /res/'
fname = resfolder + 'crawl.txt'
#savedfile = resfolder + 'trained'
dictionaryfile = resfolder + 'dict.txt'
psgfile = resfolder + 'psg.txt'


Gen = generator.SuggestionGenerator(dictionaryfile, psgfile)
freq = dict()
freq[1] = 0
freq[3] = 0
freq[5] = 0
freq[10] = 0
freq[-1] = 0

############ testing ##################
total_sample = 0


def check_list(suggestion_list, target_line):
    counter = 0
    for i in suggestion_list:
        counter = counter+1
        if(i == target_line):
            return counter
    return 100  # not found


def remove_new_line(sentence):
    temp = sentence.split('\n')
    return temp[0]


def test(input_file, output_file):
    global Gen
    global freq
    global total_sample
    f = open(input_file, "r")
    line = f.readlines()
    f.close()
    print len(line)
    f = open(output_file, "w")
    i = 0
    while (i < len(line)):
        real_line = remove_new_line(line[i])
        error_line = remove_new_line(line[i+1])
        # print real_line," ",error_line #Line removed 1
        result = Gen.gen(error_line)
        idx = check_list(result, real_line)
        print "i = ", i, " ", "idx = ", idx
        total_sample = total_sample + 1
        if(idx == 1):
            freq[1] = freq[1]+1
        if(idx < 3):
            freq[3] = freq[3]+1
        if(idx < 5):
            freq[5] = freq[5]+1
        if(idx < 10):
            freq[10] = freq[10]+1
        if(idx > 10):
            freq[-1] = freq[-1]+1

        a = "main: "+line[i]
        b = "error: "+line[i+1]
        # f.write(a) #line removed 2
        # f.write(b) #line removed 3
        # f.write("suggestion List:\n") #line removed 4
        #print real_line," ",error_line
        """
        #segment removed 5 
        for j in result:
            print j
            f.write(j+'\n') 
        """
        i = i+2

    f.close()
    print (freq[1]*100)/total_sample, " ", (freq[3]*100) / \
        total_sample, " ", (freq[5]*100) / \
        total_sample, " ", (freq[10]*100)/total_sample


# data set running code
# 1:  res/Paper Dataset/Final Dataset/spell_checker_dataset_bellayetbot_1k.txt
# 2:  res/Paper Dataset/Final Dataset/spell_checker_dataset_somewhereindata_1k.txt
# 3:  res/Paper Dataset/Final Dataset/spell_checker_dataset_vashaShikkha_1k.txt

test("res/Paper Dataset/Final Dataset/spell_checker_dataset_vashaShikkha_1k.txt",
     "res/Paper Dataset/Final Dataset/spell_checker_dataset_vashaShikkha_1k_output.txt")


"""
sentence = str(raw_input())
print(str)
ret = Gen.gen(sentence)
for rets in ret:
    print(rets)
"""
