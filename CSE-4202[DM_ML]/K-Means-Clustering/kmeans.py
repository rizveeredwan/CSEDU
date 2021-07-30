#!/usr/bin/env python2
# -*- coding: utf-8 -*-
"""
Created on Sun Nov  4 10:38:11 2018

@author: rizvee
"""
import random

class K_Means_Clusturing:
    def __init__(self,n):
        self.points=[] 
        self.k=n
        self.cluster_center=[]
        self.clusters = []
        pass 
    def read(self,filename):
        f=open(filename,"r")
        lines = f.readlines()
        f.close()
        for i in lines:
            temp=i.split()
            for j in range(0,len(temp)):
                temp[j]=int(temp[j])
            self.points.append(temp)
        print (self.points)
        return 
    def initialization(self):
        choice = int(input("Press 1 for Random Cluster Centers\nPress 2 for Input Cluster Centers\n "))
        if(choice == 1):
            while(len(self.cluster_center) != self.k):
                v=random.randint(-1,self.k-1) #generates between 0 to k-1 
                if(self.points[v] not in self.cluster_center):
                    self.cluster_center.append(self.points[v])
            print (self.cluster_center)
        else:
            while(len(self.cluster_center) !=self. k):
                v=int(input("Index number which will be clusters: "))
                if(self.points[v] not in self.cluster_center):
                    self.cluster_center.append(self.points[v])
                else:
                    print ("This index is already been considered for center")
            print (self.cluster_center)
        return 
    def disimilarity(self,point,center):
        value = 0.0
        for i in range(0,len(point)):
            v = (point[i]-center[i]) * (point[i]-center[i])
            value = value + v 
        return value
    def find_center(self,list_of_points):
        sum_value = []
        for i in range(0,len(list_of_points[0])):
            sum_value.append(0)
        for i in range(0,len(list_of_points)):
            temp = list_of_points[i]
            for j in range(0,len(temp)):
                sum_value[j]=sum_value[j]+temp[j]
        for i in range(0,len(sum_value)):
            sum_value[i]=(sum_value[i]*1.0)/(len(list_of_points))
        return sum_value 
    def make_cluster(self):
        iteration = 0
        same=0
        while(True):
            iteration=iteration+1
            partitions = []
            for i in range(0,len(self.cluster_center)):
                temp = []
                partitions.append(temp) 
            for i in range(0,len(self.points)):
                temp=self.points[i]
                mx_disimilarity = 100000000000
                found_center = -1
                for j in range(0,len(self.cluster_center)):
                    center = self.cluster_center[j]
                    diff = self.disimilarity(temp,center)
                    if(mx_disimilarity>diff):
                        mx_disimilarity=diff
                        found_center=j 
                partitions[found_center].append(self.points[i])
            #print "partitions = ",partitions
            if(partitions == self.clusters):
                same=same+1
                if(same==10):
                    break 
            else:
                self.clusters=partitions
                same=0
                self.cluster_center = []
                for i in self.clusters:
                    new_center = self.find_center(i)
                    self.cluster_center.append(new_center)
            
        print ("iteration = ",iteration) 
        print ("cluster centers = ",self.cluster_center)
        print ("clusters = ",self.clusters)
        return
    def show_clusters(self,point_list):
        return 
    
    
    

    

def main():
    obj = K_Means_Clusturing(3)
    obj.read("input.txt") 
    obj.initialization()
    obj.make_cluster()

main() 
print ("done")

"""
from sklearn.cluster import KMeans
import numpy as np
X = np.array([[1, 2], [3, 4], [5,6],[2,5],[6,7],[8,9],[4,10]])
X = np.array([[2,10],[2,5],[8,4],[5,8],[7,5],[6,4],[1,2],[4,9]])
kmeans = KMeans(n_clusters=3, random_state=0).fit(X)
print kmeans.labels_
#kmeans.labels_
#array([0, 0, 0, 1, 1, 1], dtype=int32)

#array([0, 1], dtype=int32)print 
print kmeans.cluster_centers_
"""


import matplotlib.pyplot as plt
import numpy as np
import random

x = np.zeros(1000)
y = np.zeros(1000)
for i in range(len(x)):
    x[i] = random.random()
    y[i] = random.random()

plt.plot(x,y,'k,')
plt.show()

