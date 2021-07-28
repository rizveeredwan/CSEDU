#!/usr/bin/env python2
# -*- coding: utf-8 -*-
"""
Created on Fri Oct 12 01:14:59 2018

@author: rizvee
"""

import math
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
        
#class to make decision tree 
class Decision_Tree():
    def __init__(self):
        self.node_attr = "" #decision parameter of this node 
        self.class_label = "" #if this node gives result or not 
        self.child_list = dict() #child nodes to decide going down 
        self.parent = "" 
        self.special_decision="" #special decision 
    def learn(self,feature_matrix,class_matrix,valid_row_list,valid_attr_list):
        class_list =self.calculate_unique_value_col(class_matrix,valid_row_list,0)
        if(len(class_list)==1):
            #final decision parameter been found 
            self.class_label=class_list[0]
            self.special_decision=self.class_label 
            return 
        else:
            #need to break down more
            self.calculate_gain_for_a_feature(feature_matrix,class_matrix,valid_row_list,0,class_list)
            #special_decision section 
            best_res=-1
            best_dec=""
            #print "class list = ",class_list
            temp_count_dict= dict()
            for i in class_list:
                temp_count_dict[i]=0
                
            for i in range(0,len(valid_row_list)):
                r=valid_row_list[i]
                v=class_matrix[r][0]
                temp_count_dict[v]=temp_count_dict[v]+1 
                if(temp_count_dict[v]>best_res):
                    best_res=temp_count_dict[v]
                    best_dec=v
            self.special_decision=best_dec
            
            max_res = -1000000000000
            best_feature = -1
            for i in valid_attr_list:
                res = self.calculate_gain_for_a_feature(feature_matrix,class_matrix,valid_row_list,i,class_list)
                if(res>max_res):
                    max_res=res
                    best_feature=i 
            
            if(best_feature == -1):
                #print "probabilistic class level defined."
                prob_class_label = dict()
                for i in valid_row_list:
                    if(class_matrix[i][0] not in prob_class_label):
                        prob_class_label[class_matrix[i][0]]=1 
                    else:
                        prob_class_label[class_matrix[i][0]]=prob_class_label[class_matrix[i][0]]+1
                max_counter = -1
                save = ""
                #print prob_class_label
                for i in prob_class_label:
                    value = prob_class_label[i]
                    if(value>max_counter):
                        value=max_counter
                        save = i
                self.class_label=save
                #print "decided label: ",self.class_label
                return
            
            self.node_attr = best_feature
            unique_value_col = self.calculate_unique_value_col(feature_matrix,valid_row_list,best_feature)
            new_valid_attr_list = self.remove_attribute_from_list(valid_attr_list,best_feature)
            for i in unique_value_col:
                self.child_list[i]=Decision_Tree()
                self.child_list[i].parent=self 
                new_valid_row_list = self.extract_row(feature_matrix,valid_row_list,best_feature,i)
                self.child_list[i].learn(feature_matrix,class_matrix,new_valid_row_list,new_valid_attr_list)    
    
    def prediction(self,test_attribute_list):
        if(self.class_label != ""):
            #print "predicted: ",self.class_label
            return self.class_label
        else:
            attr_value = test_attribute_list[self.node_attr]
            if(attr_value in self.child_list):
                next_node = self.child_list[attr_value]
                return next_node.prediction(test_attribute_list)
            else:
                #print "decision tree didn't learn"
                #print "special ",self.special_decision
                return self.special_decision
    def calculate_unique_value_col(self,matrix,valid_row_list,col_num): #function to calculate unique value in a column
        temp = []
        row=len(valid_row_list)
        for i in range(0,row):
            target = valid_row_list[i]
            if(matrix[target][col_num] not in temp):
                temp.append(matrix[target][col_num])
        return temp
    def calculate_information_gain(self,list_labels):
        
        value = 0
        base=0
        dominator=0
        for i in list_labels:
            base=base+1
            dominator=dominator+i
        result=0
        for i in list_labels:
            value = (-i*1.0)/(dominator)
            if(value != 0):
                result=result+(value*1.0*math.log(-value,base))
        return result 
   
    def calculate_gain_for_a_feature(self,feature_matrix,class_matrix,valid_row_list,col_num,labels):
        #count section 
        attr_unique_val = dict() 
        row = len(valid_row_list)
        for i in range(0,row):
            target_row = valid_row_list[i]
            attr_val = feature_matrix[target_row][col_num]
            if(attr_val in attr_unique_val):
                l=class_matrix[target_row][0]
                attr_unique_val[attr_val][l]=attr_unique_val[attr_val][l]+1
            else:
                attr_unique_val[attr_val] = dict()
                for j in labels:
                    attr_unique_val[attr_val][j] = 0 #no
                    if(class_matrix[target_row][0] == j):
                        attr_unique_val[attr_val][j] = 1
        
        #information gain calculation section
        sum_label = []
        for i in range(0,len(labels)):
            sum_label.append(0)
        
        result_information_gain = [] 
        for i in attr_unique_val:
            local_sum=[]
            for j in range(0,len(labels)):
                sum_label[j] = sum_label[j]+attr_unique_val[i][labels[j]]
                local_sum.append(attr_unique_val[i][labels[j]])
            I = self.calculate_information_gain(local_sum)
            result_information_gain.append(I) 
            
        #entropy calculation section 
        dominator = 0
        cnt=0
        entropy=0
        for i in sum_label:
            dominator = dominator + i 
        for i in attr_unique_val:
            value = 0
            for j in labels:
                value = value*1.0 +  attr_unique_val[i][j]
            value = value * 1.0 * result_information_gain[cnt]
            value = (value*1.0)/dominator
            entropy=entropy+value
            cnt=cnt+1 
            
        #gain calculation section 
        table_information_gain = self.calculate_information_gain(sum_label)
        gain = table_information_gain - entropy 
        return gain
    def extract_row(self,feature_matrix,valid_row_list,feature_number,feature_specific_value):
        new_row_list = []
        for i in valid_row_list:
            temp = feature_matrix[i][feature_number]
            if(temp==feature_specific_value):
                new_row_list.append(i)
        return new_row_list 
    def remove_attribute_from_list(self,valid_attr_list,attr):
        new_valid_attr_list = []
        for i in valid_attr_list:
            if(i != attr):
                new_valid_attr_list.append(i)
        return new_valid_attr_list
    def print_decision_tree(self,mapped_attribute):
        if(self.class_label != ""):
            print "decision node: ",self.class_label
            return
        print "Attribute to take decision: ",mapped_attribute[self.node_attr]
        for i in self.child_list:
            print "here going down: ",i
            self.child_list[i].print_decision_tree(mapped_attribute)

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
        unique_class_label = self.calculate_unique_value_in_col(class_matrix,0)
        f_measure_dict = dict()
        for i in unique_class_label:
            f_measure_dict[i] = 0
        valid_row_list = [] 
        valid_attr_list = []
        
        base=0
        counter=0
        for i in range(0,len(self.learn_sample_list)):
            learn_range = self.learn_sample_list[i]
            #rows to work with 
            for j in range(base,learn_range+1):
                valid_row_list.append(j)
            #print "base = ",base," ",learn_range," ",len(valid_row_list)
            #features to work with 
            valid_attr_list = []
            for j in range(0,len(feature_matrix[0])):
                valid_attr_list.append(j) 
            #learning phase 
            decision_tree = Decision_Tree()
            decision_tree.learn(feature_matrix,class_matrix,valid_row_list,valid_attr_list)
            print "learning done upto ",learn_range," total = ",len(feature_matrix)
            
            if((learn_range+1)==len(feature_matrix)):
                break
            counter=counter+1
            #decision_tree.print_decision_tree(obj.attibutes)
            #testing phase
            f_measure = F_Measure(unique_class_label)
            for j in range(learn_range+1,len(feature_matrix)):
                #prediction
                test_list = []
                for k in feature_matrix[j]:
                    test_list.append(k)
                res = decision_tree.prediction(test_list)
                f_measure.update_result(res,class_matrix[j][0])
            res = f_measure.calculate_f_measure(unique_class_label)
            
            for j in f_measure_dict:
                f_measure_dict[j] = f_measure_dict[j]+res[j] 
            print f_measure_dict
            accuracy = f_measure.accuracy()
            print "accuracy = ",accuracy
            if((learn_range+1)<len(feature_matrix)):
                base=learn_range+1
            
        for i in f_measure_dict:
            f_measure_dict[i] = (f_measure_dict[i]*100.0)/(counter)
        print f_measure_dict
        
            
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
    valid_col_list = []
    for i in range(0,len(obj.feature_matrix)):
        valid_row_list.append(i)
    for i in range(0,len(obj.feature_matrix[0])):
        valid_col_list.append(i) 
    #decision tree section 
    decision_tree = Decision_Tree()
    decision_tree.learn(obj.feature_matrix,obj.class_matrix,valid_row_list,valid_col_list)
    decision_tree.print_decision_tree(obj.attibutes)
    
    #print "learn phase complete" 
    #test_data =['systems','26-30','46-50k']
    #print "test data: ",test_data
    #decision_tree.prediction(test_data)
    #pass
    """
    ###Dataset 1:  "Dataset/Balance sheet/train.txt" 
    ###Dataset 2: "Dataset/Car /car" 
    ###Dataset 3:  "Dataset/Hayes-Roth/train.txt"
    ###Dataset 4: "Dataset/TicTacToe/tic tac toe"
    ###Dataset 5: "Dataset/Heart Data/train.txt"
    
    obj = ReadingFile()
    obj.read_txt_file("Dataset/Car /car")
    
    cross_validation = Cross_Validation(10,len(obj.feature_matrix))
    cross_validation.process_calculation(obj)
    
    
    print "done"

main() 

