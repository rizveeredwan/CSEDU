import numpy as np
import codecs
import math

#EMBEDDING_DIM or feature vector
EMBEDDING_DIM=5

#reading vectors from file along with words
#positive words
positiveWord=[]
positiveWordNumber={}
positiveWordVector=[]

#negative words
negativeWord=[]
negativeWordNumber={}
negativeWordVector=[]

#neutral words
neutralWord=[]
neutralWordNumber={}
neutralWordVector=[]



def readFromFile(fileName):
    checkWordNumber = {}
    checkWordVector = []
    checkWord = []

    print("ase")
    with open(fileName) as file:
        reader = file.readlines()
        counter = -1;
        tempVector = []
        for line in reader:
            counter = counter + 1
            if counter == 0:
                length = len(line)
                line = line[0:length - 1]
                checkWord.append(line)
                length = len(checkWord)
                checkWordNumber[line] = length - 1
            elif counter == EMBEDDING_DIM:
                length = len(line)
                line = line[0:length - 1]
                variable = float(line)
                tempVector.append(variable)
                checkWordVector.append(tempVector)
                tempVector = []
                counter = -1
            else:
                length = len(line)
                line = line[0:length - 1]
                variable = float(line)
                tempVector.append(variable)

    print(len(checkWord))
    if fileName=="positiveVector":
        length = len(checkWord)
        i=0
        while i<length:
            positiveWord.append(checkWord[i])
            positiveWordVector.append(checkWordVector[i])
            i=i+1
        i=0
        for word in positiveWord:
            positiveWordNumber[word]=i
            i=i+1
    elif fileName=="negativeVector":
        length = len(checkWord)
        i = 0
        while i < length:
            negativeWord.append(checkWord[i])
            negativeWordVector.append(checkWordVector[i])
            i = i + 1
        i = 0
        for word in negativeWord:
            negativeWordNumber[word] = i
            i = i + 1
    elif fileName=="neutralVector":
        print("new")
        length = len(checkWord)
        i = 0
        while i < length:
            neutralWord.append(checkWord[i])
            neutralWordVector.append(checkWordVector[i])
            i = i + 1
        i = 0
        for word in neutralWord:
            neutralWordNumber[word] = i
            i = i + 1

    print("done for "+ " " + str(fileName))


#reading from files
#function call
readFromFile("positiveVector")
readFromFile("negativeVector")
readFromFile("neutralVector")


#common word
commonWord=[]
result=[]

EMBEDDING_DIM=5

def vectorDifference(vector1,vector2):
    i=0
    ans=0
    while i<EMBEDDING_DIM:
        ans= ans + (vector1[i]-vector2[i])*(vector1[i]-vector2[i])
        i=i+1
    ans=math.sqrt(ans)
    return ans

def cosineDistance(vector1,vector2):
    i = 0
    ans = 0
    while i < EMBEDDING_DIM:
        ans = ans + (vector1[i]) * (vector2[i])
        i = i + 1
    return ans

for word in positiveWord:
    if (word in negativeWord and word in neutralWord):
        #word is common
        #taking positive vector
        value1=positiveWordNumber[word]
        vector1=positiveWordVector[value1]

        #taking negative vector
        value2=negativeWordNumber[word]
        vector2=negativeWordVector[value2]

        value3=neutralWordNumber[word]
        vector3=neutralWordVector[value3]

        commonWord.append(word)
        result.append(vectorDifference(vector1,vector2))
        print(word+ " "+ str(vectorDifference(vector1,vector2)) + " " + str(vectorDifference(vector1,vector3)))
