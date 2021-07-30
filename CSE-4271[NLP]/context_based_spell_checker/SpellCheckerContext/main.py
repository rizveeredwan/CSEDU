#!/usr/bin/python
# -*- coding: utf-8 -*-


import Tkinter as tk
import random
from SpellChecker.suggestiongenerator import SuggestionGenerator 
import tkFont




resfolder = '/home/rizvee/Books/4-2/NLP/Work/Dataset/kenlm/SpellCheckerContext /res/'
fname = resfolder + 'crawl.txt'
#savedfile = resfolder + 'trained'
dictionaryfile = resfolder + 'dict.txt'
psgfile = resfolder + 'psg.txt'


checker = SuggestionGenerator(dictionaryfile,psgfile)


class SpellCheckerBengali:
    def __init__(self, s):
        word = s.split()
        self.sentence=""
        for i in word:
            if(self.sentence == ""):
                self.sentence = i 
            else:
                self.sentence = self.sentence+" "+i
    def isCorrect(self,sugg):
        counter=0
        for i in sugg:
            counter=counter+1
            save = i.split()
            s=""
            for j in save:
                if(s==""):
                    s=j 
                else:
                    s=s+" "+j 
            if(s.decode('utf-8')==self.sentence and counter<=3): #self.sentence is in 'utf-8' 
                print "correct sentence"
                return True 
        print "incorrect sentence" 
        return False 
    def suggestions(self,sugg): 
        res=[]
        print "suggestions"
        for i in range(3):
            s=sugg[i] 
            print s," ",type(s)
            res.append(s) #converts from unicode to string
        return res

class CheckerWindow(tk.Frame):
    def __init__(self, master):
        tk.Frame.__init__(self,
                          master,
                          width=300,
                          height=200)
        self.master.title('Spell Checker 1.0.0')
        self.labels=[]
        self.pack_propagate(0)
        self.pack()
        self.recipient_var = tk.StringVar()
        self.recipient = tk.Entry(self,textvariable=self.recipient_var)
        self.recipient_var.set('Mathematics')
        self.go_button = tk.Button(self,text='Check',command=self.print_out)
        self.go_button.pack(fill=tk.X, side=tk.BOTTOM)
        self.recipient.pack(fill=tk.X, side=tk.TOP)
 
    def print_out(self):
        for label in self.labels: 
            label.destroy()
            
        bengal = SpellCheckerBengali(self.recipient_var.get())
        print bengal.sentence
        global checker
        sugg = checker.gen(bengal.sentence.encode('utf-8'))
        if bengal.isCorrect(sugg) == True: 
            label = tk.Label(self, text= "The word "+self.recipient_var.get()+" is correctly spelled")
            label.pack()
            self.labels.append(label)
        
        else:
            suggList = bengal.suggestions(sugg)
            label = tk.Label(self, text= "The word is incorrectly spelled. Suggestions: ")
            label.pack()
            self.labels.append(label)
            for suggword in suggList:
                appHighlightFont = tkFont.Font(family='lucida', size=12, weight='bold')
                label = tk.Label(self, text= " - "+suggword,font=appHighlightFont)
                label.pack()
                self.labels.append(label)
        #print('Suggestion: %s' % (self.recipient_var.get()))
    def run(self):
        self.mainloop()
 


app = CheckerWindow(tk.Tk())
app.run()
