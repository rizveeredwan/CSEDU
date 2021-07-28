#!/usr/bin/env python2
# -*- coding: utf-8 -*-
"""
Created on Sat Oct 27 21:21:38 2018

@author: rizvee
"""

class F_Measure:
    def __init__(self,class_label):
        print "Yeah"
        self.measure = dict()
        for i in class_label:
            self.measure[i]=dict()
            self.measure[i]["true positive"]=0
            self.measure[i]["false positive"]=0
            self.measure[i]["true negative"]=0
            self.measure[i]["false negative"]=0
            self.sample=0
            self.correct=0
    def calculate_f_measure(self,class_label):
        result = dict()
        for i in class_label:
            precision=self.calculate_precision(i)
            recall=self.calculate_recall(i)
            if((precision+recall) == 0):
                result[i]=0
            else:
                value = 2.0 * precision * recall
                value = (value * 1.0)/(precision+recall)
                result[i]=value  
        return result
    def calculate_precision(self,index):
        lob = self.measure[index]["true positive"]
        hor = self.measure[index]["true positive"]+self.measure[index]["false positive"]
        if(hor==0):
            return 0
        else:
            precision=(lob*1.0)/(hor)
            return precision
        return
    def calculate_recall(self,index):
        lob = self.measure[index]["true positive"]
        hor = self.measure[index]["true positive"]+self.measure[index]["false negative"]
        if(hor==0):
            return 0
        else:
            recall=(lob*1.0)/(hor)
            return recall
        return
    def update_result(self,got_result,target_result):
        self.sample=self.sample+1 
        if(got_result not in self.measure):
            #special updates 
            self.measure[target_result]["false negative"] = self.measure[target_result]["false negative"]+1
            return
        if(got_result == target_result):
            self.correct=self.correct+1
            self.measure[got_result]["true positive"]=self.measure[got_result]["true positive"]+1
        else:
            self.measure[got_result]["false positive"]=self.measure[got_result]["false positive"]+1
            self.measure[target_result]["false negative"]=self.measure[target_result]["false negative"]+1
        return
    def accuracy(self):
        print "correct = ",self.correct," ",self.sample
        return (self.correct*100.0)/(self.sample)
    