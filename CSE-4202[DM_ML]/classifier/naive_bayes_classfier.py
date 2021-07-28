#!/usr/bin/env python2
# -*- coding: utf-8 -*-
"""
Created on Sun Oct 14 08:46:54 2018

@author: rizvee
"""

from F_Measure import F_Measure


class ReadingFile:
    def __init__(self):
        self.feature_matrix=[]
        self.class_matrix=[] 
        pass
    def removing_new_line(self,string):
        temp = string.split('\n')
        temp=temp[0]
        return temp 
    def read_txt_file(self,filename):
        f=open(filename,"r")
        line = f.readlines() 
        #attribute collection 
        attribute_info = line[0]
        attribute_info = self.removing_new_line(attribute_info)
        self.attibutes = attribute_info.split(',')
        #value collection and matrix formation 
        for i in range(1,len(line)):
            take = line[i]
            take=self.removing_new_line(take)
            take=take.split(',')
            take1=[]
            for i in range(0,len(take)-1):
                take1.append(take[i]) #feature 
            self.feature_matrix.append(take1) #features 
            take2=[]
            take2.append(take[len(take)-1])
            self.class_matrix.append(take2) #class labels 
        f.close()


class Naive_Bayes_Classifier:
    
    def __init__(self):
        pass 
    
    def initiate_variables(self,feature_matrix,class_matrix):
        valid_row_list = []
        for i in range(0,len(feature_matrix)):
            valid_row_list.append(i) 
        #unique features from class 
        unique_feature_class = self.calculate_unique_value_col(class_matrix,valid_row_list,0)
        self.class_label = unique_feature_class
        self.label_counter = dict() 
        self.each_label_attr_sum = dict()
        for i in self.class_label:
            self.label_counter[i]=0 
            self.each_label_attr_sum[i]=0
       
        #counter initialization 
        
        feature_number = len(feature_matrix[0])
        secondary_dict = dict() 
        for i in range(0,feature_number):
            secondary_dict [i] = dict() 
            temp = self.calculate_unique_value_col(feature_matrix,valid_row_list,i)
            for j in temp:
                secondary_dict [i][j]=1 #laplace smoothing 
        
        self.count_dictionary = dict()
        for i in unique_feature_class:
            temp1 = dict()
            for j in secondary_dict:
                temp2 = dict()
                for k in secondary_dict[j]:
                    temp2[k]=secondary_dict[j][k]
                    self.each_label_attr_sum[i]=self.each_label_attr_sum[i]+1
                temp1[j]=temp2 
            self.count_dictionary[i] = temp1 
        return
        
    def learn(self,feature_matrix,class_matrix,valid_row_list):
        for i in valid_row_list:
            label = class_matrix[i][0] 
            self.label_counter[label] = self.label_counter[label] + 1  
            for j in range(len(feature_matrix[0])):
                attr = feature_matrix[i][j] 
                label = class_matrix[i][0]
                self.count_dictionary[label][j][attr] = self.count_dictionary[label][j][attr]+1 
                self.each_label_attr_sum[label]=self.each_label_attr_sum[label]+1
        return 
    
    def prediction(self,total_sample,list_attr):
        
        #print self.count_dictionary
        #print self.each_label_attr_sum
        goal=""
        max_prob = -100000000
        for i in self.class_label:
            result = (self.label_counter[i]*1.0+1)/(total_sample+2) #smoothing 
            for j in range(0,len(list_attr)):
                value = (self.count_dictionary[i][j][list_attr[j]]*1.0)/(self.each_label_attr_sum[i])
                result = result * value 
            if(max_prob<result):
                max_prob=result
                goal=i
       # print goal
        return goal
    
    def calculate_unique_value_col(self,matrix,valid_row_list,col_num): #function to calculate unique value in a column
        temp = []
        row=len(valid_row_list)
        for i in range(0,row):
            target = valid_row_list[i]
            if(matrix[target][col_num] not in temp):
                temp.append(matrix[target][col_num])
        return temp
    

class Cross_Validation:
    def __init__(self,folding,total_sample):
        base=(total_sample)/(folding)
        self.learn_sample_list=[]
        self.prediction_list=[]
        self.learn_sample_list.append(base)
        counter=base
        while True:
            counter=counter+base
            if(counter>=total_sample):
                counter=counter-base
                break
            else:
                self.learn_sample_list.append(counter)
    def process_calculation(self,obj):
        feature_matrix = obj.feature_matrix
        class_matrix = obj.class_matrix
        total_sample = len(feature_matrix)
        unique_class_label = self.calculate_unique_value_in_col(class_matrix,0)
        
        naive_bayes = Naive_Bayes_Classifier()
        naive_bayes.initiate_variables(feature_matrix,class_matrix)
        
        valid_row_list = []
        start=0
        accuracy_saved = 0 
        step=0
        
        #f measure save initiate
        f_measure_value_list = dict()
        for i in naive_bayes.class_label:
            f_measure_value_list[i]=0
        
        for i in range(0,len(self.learn_sample_list)):
            #learn
            value = self.learn_sample_list[i]
            while (start<=value):
                valid_row_list.append(start)
                start=start+1
            naive_bayes.learn(feature_matrix,class_matrix,valid_row_list)
            
            if(start>=total_sample):
                break
            #prediction
            step=step+1
            f_measure = F_Measure(naive_bayes.class_label)
            for j in range(start,total_sample):
                res = naive_bayes.prediction(value+1,feature_matrix[j])
                f_measure.update_result(res,class_matrix[j][0])
                
            #f measure section 
            res = f_measure.calculate_f_measure(unique_class_label)
            acc = f_measure.accuracy()
            accuracy_saved = accuracy_saved +acc 
            print "accuracy = ",acc
            for j in unique_class_label:
                f_measure_value_list[j]=f_measure_value_list[j]+res[j]
        for i in f_measure_value_list:
            f_measure_value_list[i]=(f_measure_value_list[i]*100.0)/(step)
        print f_measure_value_list
            
    def calculate_unique_value_in_col(self,matrix,col):
        row=len(matrix)
        temp = []
        for i in range(0,row):
            val = matrix[i][col]
            if(val not in temp):
                temp.append(val) 
        return temp


def main():
    """
    obj = ReadingFile()
    obj.read_txt_file("input.csv")
    valid_row_list = []
    for i in range(0,len(obj.feature_matrix)):
        valid_row_list.append(i)
    naive_bayes = Naive_Bayes_Classifier()
    naive_bayes.initiate_variables(obj.feature_matrix,obj.class_matrix)
    naive_bayes.learn(obj.feature_matrix,obj.class_matrix,valid_row_list)
    naive_bayes.prediction(len(obj.feature_matrix),["youth","high", "no","fair"])
    """
    ###Dataset 1:  "Dataset/Balance sheet/train.txt" 
    ###Dataset 2: "Dataset/Car /car" 
    ###Dataset 3:  "Dataset/Hayes-Roth/train.txt"
    ###Dataset 4: "Dataset/TicTacToe/tic tac toe"
    ###Dataset 5: "Dataset/Heart Data/train.txt"
    
    obj = ReadingFile()
    obj.read_txt_file("Dataset/TicTacToe/tic tac toe")
    
    cross_validation = Cross_Validation(10,len(obj.feature_matrix))
    cross_validation.process_calculation(obj)
    

main()