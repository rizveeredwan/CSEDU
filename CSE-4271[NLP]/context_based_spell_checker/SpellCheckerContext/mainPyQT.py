#!/usr/bin/python
# -*- coding: utf-8 -*-

"""
ZetCode PyQt4 tutorial

In this example, we create a bit
more complicated window layout using
the QtGui.QGridLayout manager.

author: Jan Bodnar
website: zetcode.com
last edited: October 2011
"""

import sys
from PyQt4 import QtGui
import timeit

from SpellChecker.suggestiongenerator import SuggestionGenerator



resfolder = '/home/rizvee/Books/4-2/NLP/Work/Dataset/kenlm/SpellCheckerContext /res/'
dictionaryfile = resfolder + 'dict.txt'
psgfile = resfolder + 'psg.txt'
generator = SuggestionGenerator(dictionaryfile,psgfile)


class Example(QtGui.QWidget):

    def __init__(self):
        super(Example, self).__init__()

        self.initUI()

    def initUI(self):

        self.title = QtGui.QLabel('Bangla Sentence')
        #author = QtGui.QLabel('Author')
        self.review = QtGui.QLabel('Status')

        self.titleEdit = QtGui.QLineEdit()
        #authorEdit = QtGui.QLineEdit()
        self.check_button = QtGui.QPushButton("check")
        self.check_button.clicked.connect(self.check_button_press)

        self.clear_button = QtGui.QPushButton("clear")
        self.clear_button.clicked.connect(self.clear_button_press)

        self.reviewEdit = QtGui.QTextEdit()

        grid = QtGui.QGridLayout()
        grid.setSpacing(10)

        grid.addWidget(self.title, 1, 0)
        grid.addWidget(self.titleEdit, 1, 1)

        #grid.addWidget(author, 2, 0)
        #grid.addWidget(authorEdit, 2, 1)
        grid.addWidget(self.check_button,2,1)
        grid.addWidget(self.clear_button,3,1)

        grid.addWidget(self.review, 4, 0)
        grid.addWidget(self.reviewEdit, 4, 1, 6, 1)

        self.setLayout(grid)

        self.setGeometry(300, 300, 350, 300)
        self.setWindowTitle('Bangla Spell Checker')
        self.show()
        # self.TIT_DatasetTest()
        # self.TIT_LM_model_score()
        self.TIT_Suggestion_Based_Score()

    def TIT_DatasetTest(self):
        global generator
        f = open('Generated_Results.txt','w')
        with open('TIT/phonetic.txt','r') as file:
            lines = file.readlines()
            for i in range(0,len(lines),1):
                try:
                    self.sentence = lines[i+1].strip()
                    sugg = generator.gen(self.sentence)
                    f.write(str(int(i/2)+1)+': '+self.sentence+'\n')
                    for j in range(0,min(10,len(sugg))):
                        f.write("sugg "+str(j)+':'+sugg[j]+'\n')
                except Exception as e:
                    print(e)
                    print("Error in ",(int(i/2)+1))
        f.close()

    def TIT_Suggestion_Based_Score(self):
        global generator
        f = open('TIT/suggestion_based_score.csv','w')
        with open('TIT/sentence_suggestion.txt','r') as file:
            lines = file.readlines()
            cnt = 0
            v = 1
            i = 0
            while i<len(lines):
                print(i,v)
                banglish = lines[i].strip()
                print(banglish)
                cnt = int(lines[i+1].strip())
                print(cnt)
                sentences = []
                for j in range(i+2,i+2+cnt,1):
                    line = lines[j].strip()
                    sentences.append(line)
                i = i+2+cnt
                sentence_with_score=[];
                for j in range(0,len(sentences)):
                    self.sentence = sentences[j]
                    lm_prob_score = generator.language_model.calculate_probability(self.sentence)
                    print(self.sentence,lm_prob_score)
                    sentence_with_score.append([lm_prob_score,self.sentence])
                sentence_with_score.sort(key = lambda x: x[0], reverse=True)
                f.write(banglish+'\n')
                for j in range(0,min(5,len(sentence_with_score))):
                    f.write(sentence_with_score[j][1]+','+str(sentence_with_score[j][0])+'\n')
        f.close()

    def TIT_LM_model_score(self):
        global generator
        f = open('TIT/prothom_alo_corpus.csv','w')
        f.write('serial,sentence,