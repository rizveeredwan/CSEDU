import random
import math
import matplotlib.pyplot as plt
import numpy as np

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

words=[]

#reading input lines
with open("TopicClusturingInput") as file:
    reader=file.readlines()

    for line in reader:
        variable =line.split()
        for each in variable:
            if(each=="\n"):
                continue
            else:
                words.append(each) #single words been taken


file.close()

#single word and type will be given
#this function will return the type of word vector for this word
def returnSingleVector(word,type):
    checkWordNumber=[]
    checkWordVector={}
    checkWord=[]

    if type==0:
        checkWordNumber = positiveWordNumber
        checkWordVector = positiveWordVector
        checkWord=positiveWord
    elif type==1:
        checkWordNumber = negativeWordNumber
        checkWordVector = negativeWordVector
        checkWord = negativeWord
    elif type==2:
        checkWordNumber = neutralWordNumber
        checkWordVector = neutralWordVector
        checkWord = neutralWord

    if word in checkWord:
        print(str(word) + " " + "yes")
        # word found
        number = checkWordNumber[word]
        return  checkWordVector[number]
    else:
        print (str(word) + " " + "no")
        tempVector = []
        i = 0
        while i < EMBEDDING_DIM:
            tempVector.append(1.0)
            i = i + 1
        return tempVector;

#this function calculates cluster average
def calculatingAvg(clusterResult):
    print("cluster calculation avg")
    l = 0
    avg = []
    while l < EMBEDDING_DIM:
        avg.append(0)
        l = l + 1
    k=0
    while k<len(clusterResult):
        j=0
        while j<EMBEDDING_DIM:
            avg[j]=avg[j]+clusterResult[k][j]/len(clusterResult)
            j=j+1
        k=k+1
    return avg




#this function makes clusturing and display
def clusturing(type):

    #cluster vectors
    cluster=[]
    clusterResult0=[]
    clusterResult1=[]
    clusterNumber=2
    wordList0=[]
    wordList1=[]
    i=0
    while i<clusterNumber:
        j=0
        v=[]
        while j<EMBEDDING_DIM:
            v.append(0)
            j=j+1
        cluster.append(v)
        i=i+1

    #clusturing
    resultVectors=[]
    for each in words:
        print(each)
        vector=returnSingleVector(each,type)
        resultVectors.append(vector)
    n_iter=5
    i=0
    while i<n_iter:
        #pick k random cluster
        if i==0:
            print("choosing randomly")
            j=0
            while j<EMBEDDING_DIM:
                cluster[0][j]=random.randint(0,5)
                j=j+1
            j=0
            while j<EMBEDDING_DIM:
                cluster[1][j]=random.randint(0,5)
                j=j+1

            length=len(resultVectors)
            k=0
            wordList0=[]
            wordList1=[]
            while k<length:
                diff1=vectorDifference(cluster[0],resultVectors[k])
                diff2=vectorDifference(cluster[1],resultVectors[k])
                minimum=min(diff1,diff2)
                print(str(diff1)+" "+str(diff2))
                if(minimum == diff1):
                  clusterResult0.append(resultVectors[k])
                  wordList0.append(words[k])
                else:
                    clusterResult1.append(resultVectors[k])
                    wordList1.append(words[k])
                k=k+1
            print(len(clusterResult0))
            print(len(clusterResult1))
            avg=calculatingAvg(clusterResult0)
            k=0
            while k<EMBEDDING_DIM:
                cluster[0][k]=avg[k]
                k=k+1
            avg=calculatingAvg(clusterResult1)
            k=0
            while k<EMBEDDING_DIM:
                cluster[1][k]=avg[k]
                k=k+1
        else:
            print("calculation by average")
            clusterResult0=[]
            clusterResult1=[]
            wordList0=[]
            wordList1=[]
            length = len(resultVectors)
            k = 0
            while k < length:
                diff1 = vectorDifference(cluster[0], resultVectors[k])
                diff2 = vectorDifference(cluster[1], resultVectors[k])
                minimum = min(diff1, diff2)
                print(str(diff1) + " " + str(diff2))
                if (minimum == diff1):
                    clusterResult0.append(resultVectors[k])
                    wordList0.append(words[k])
                else:
                    clusterResult1.append(resultVectors[k])
                    wordList1.append(words[k])
                k = k + 1
            avg = calculatingAvg(clusterResult0)
            k = 0
            while k < EMBEDDING_DIM:
                cluster[0][k] = avg[k]
                k = k + 1
            avg = calculatingAvg(clusterResult1)
            k = 0
            while k < EMBEDDING_DIM:
                cluster[1][k] = avg[k]
                k = k + 1
        i=i+1
    #clusturing done now visualization
    print("calculationDone")
    from sklearn.manifold import TSNE
    if type==0:
        print("positive cluster Result")
    if type==1:
        print("negative cluster Result")
    if type==2:
        print("neutral cluster Result")
    print("cluster 0 includes")
    for var in wordList0:
        print(var+" ")
    print("\n")
    print("cluster 1 includes")
    for var in wordList1:
        print(var+" ")
    print("\n")
    model = TSNE(n_components=2, random_state=0)
    np.set_printoptions(suppress=True)
    clusterResult0 = model.fit_transform(clusterResult0)

    from sklearn import preprocessing

    normalizer = preprocessing.Normalizer()
    clusterResult0 = normalizer.fit_transform(clusterResult0, 'l2')
    fig, ax = plt.subplots()
    i=0
    for var in wordList0:
        print(var)
        ax.annotate(var.decode("utf-8"), (clusterResult0[i][0],clusterResult0[i][1]))
        i=i+1

    plt.show()

#this function finds vector difference
def vectorDifference(vector1,vector2):
    i=0
    ans=0
    while i<EMBEDDING_DIM:
        ans= ans + (vector1[i]-vector2[i])*(vector1[i]-vector2[i])
        i=i+1
    ans=math.sqrt(ans)
    return ans

clusturing(0)
clusturing(1)
clusturing(2)


