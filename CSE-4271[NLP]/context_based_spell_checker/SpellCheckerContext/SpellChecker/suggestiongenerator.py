#!/usr/bin/python
# -*- coding: utf-8 -*-

#language model import
from languagemodel import CalculationLM

#from SpellChecker.word2vec import word2vec as w2v
from SpellChecker import editdistance
import SpellChecker.editdistance as ed
import math
import timeit


def toStringX(x):
    ret = "00"
    ret = str(x/10)+str(x%10)
    return ret

class SuggestionGenerator:
    def __init__(self,dictionaryfile, psgfile):
        #self.w2vmodel = w2v(fname, savedfile) #bad
        self.dictionary = self.makedictionary(dictionaryfile)
        self.M = self.makepsg(psgfile)
        print("Generating LM: ")
        train_st = timeit.default_timer()
        self.language_model = CalculationLM() #language model
        train_en = timeit.default_timer()
        print("training time = ",train_en-train_st)

    def makedictionary(self, fname):
        M={}
        V=[]
        md = open(fname, "r")
        temstr=md.read().splitlines()
        topush=''
        cnt = 1
        for temstrs in temstr:
            topush=''
            topush=str(temstrs)
            ## print    (topush)
            M[topush] = cnt
            cnt = cnt + 1
        md.close()
        return M

    def makepsg(self, fname):
        M={}
        V=[]
        md = open(fname, "r")
        temstr=md.read().splitlines()
        topush=''
        cnt = 0
        for temstrs in temstr:
            if str(temstrs) is "#":
                cnt+=1
            else :
                topush=''
                topush=str(temstrs)
            #    # print    (topush)
                M[topush] = cnt
        md.close()
        return M

    def inDictionary(self, word):
        if (word in self.dictionary):
            return True
        return False

    def isCorrect(self, sentence):
        ret = -1
        for word in sentence:
            ret = ret + 1
            # print    (word)
            if (self.inDictionary(word) == False):
                return ret
        return -1

    def singleWordSuggestions(self, word):
        tmp=''
        tmp=str(word[0:3])
        #print    (word, tmp)

        filename = "./res/groups/"+toStringX(self.M[tmp])+"/inpy.txt"

        md = open(filename, "r")
        temstr=md.read().splitlines()

        minval = 100
        ret = []
        pseudo = []
        for temstrs in temstr:
            cur = str(temstrs)
            newval = ed.editDistanceBengali(cur, word)
            pseudo.append([cur, newval])
        pseudo = sorted(pseudo, key=lambda sug: sug[1])
        idx = 0
        lim = min(len(pseudo), 100)
        while (idx < lim):
            ret.append(pseudo[idx])
            idx = idx + 1
        # print    ("single owrd suggestions: ", str(len(ret)))
        return ret

    def sed (self, sentence, idx):
        gen = self.singleWordSuggestions(sentence[idx])
        ret = []
        for suggestion in gen:
            newsuggestion = []
            i = 0
            for word in sentence:
                if (idx != i):
                    newsuggestion.append(sentence[i])
                else:
                    newsuggestion.append(suggestion[0])
                i = i + 1
            ret.append([newsuggestion, suggestion[1]])
        # print    ("them suggestions: ", len(ret))
        return ret

    def magic(self, sentence):
        #return sentence[1] * self.w2vmodel.probabilityOfText(sentence[0])
        return

    def word_to_sentence(self,list_words):
        sentence = ""
        for i in list_words:
            if(sentence==""):
                sentence=i
            else:
                sentence=sentence+" "+i
        return sentence

    def trim (self, suggestions):
        ret = []
        #print    (len(suggestions))
        for sug in suggestions:
            #print    ("at")
            for s in sug[0:min(100, len(sug) )]:
                ## print    (s)
                ret.append(s)
        # print    (ret[0])

        ret = sorted(ret, key=lambda sug: sug[1])
        #print("length = " + str(len(ret)))

        for rets in ret:
            #rets.append(self.w2vmodel.probabilityOfText([rets[0]]))
            """
            Language Model introduce
            """
            sentence = self.word_to_sentence(rets[0])
            #print "sentence = " ,sentence
            value = self.language_model.calculate_probability(sentence)
            #print "probability ",value
            rets.append(value)

        #print    (ret)
        edit_distance_dominator = 100000000
        language_model_dominator = 0
        for rets in ret:
            edit_distance_dominator = max(rets[1],edit_distance_dominator)
            language_model_dominator = min(rets[2],language_model_dominator)

        alpha = 0
        print sug[0][0]," ",sug[0][1]," ",sug[0][2]
        ret = sorted(ret, key= lambda sug: alpha*((sug[1])/edit_distance_dominator)+(1-alpha)*((sug[2])/language_model_dominator), reverse  = False)
        okay = []
        for rets in ret:
            okay.append(' '.join(rets[0]) )
        return okay


    def gen(self, sentence):
        print "sentence = ",sentence," ",type(sentence)
        listOfSuggestions = []
        sentence = sentence.split()
        idx = self.isCorrect(sentence)
        # idx stores the index of the misspelt word
        # if no word is misspelt, then idx is -1
        if (idx != -1):
            listOfSuggestions.append(self.sed(sentence, idx) )
        else:
            idx = 0
            for word in sentence:
                #print "word = ",word
                listOfSuggestions.append(self.sed(sentence, idx ) )
                idx = idx + 1
        listOfSuggestions = self.trim(listOfSuggestions)
        #for trims in listOfSuggestions:
            #print(trims)
        return listOfSuggestions[0:min(10, len(listOfSuggestions))]
