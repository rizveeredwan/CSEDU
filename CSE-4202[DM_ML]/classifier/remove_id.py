#!/usr/bin/env python2
# -*- coding: utf-8 -*-
"""
Created on Sun Oct 28 01:40:38 2018

@author: rizvee
"""
filename="/home/rizvee/Books/4-2/Data Mining/Lab/Lab5/Dataset/Hayes-Roth/Hayes-Roth"
f=open(filename,"r") 
lines = f.readlines()
f.close()

filename="/home/rizvee/Books/4-2/Data Mining/Lab/Lab5/Dataset/Hayes-Roth/train.txt"
f=open(filename,"w")

for i in lines:
    temp=i.split()
    temp=temp[0].split(',')
    save=""
    for j in range(1,len(temp)):
        if(save==""):
            save=temp[j]
        else:
            save=save+","+temp[j]
    f.write(save+'\n')
f.close()
    
    
