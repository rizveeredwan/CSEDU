import csv
import codecs

#reading csv file
#opening file

#for positive words
positiveWord=[]
#for negative words
negativeWord=[]
#for neutral word
neutralWord=[]

#reading file and identifying the positive and negative lines
with open("AnnotatedComments.csv",'r') as csvFile:
    csvReader = csv.reader(csvFile)
    i=0
    for line in csvReader:
        i=i+1
        if i>1:
           if(line[2]=="neutral"):
            if(len(neutralWord) != 0):
                lastLine=neutralWord[len(neutralWord)-1]
                if(lastLine != line[1]):
                    neutralWord.append(line[1])
            else:
                neutralWord.append(line[1])
           elif(line[2]=="positive"):
               if (len(positiveWord) != 0):
                   lastLine = positiveWord[len(positiveWord) - 1]
                   if (lastLine != line[1]):
                       positiveWord.append(line[1])
               else:
                   positiveWord.append(line[1])
           elif(line[2]=="negative"):
               if (len(negativeWord) != 0):
                   lastLine =  negativeWord[len(negativeWord) - 1]
                   if (lastLine != line[1]):
                       negativeWord.append(line[1])
               else:
                   negativeWord.append(line[1])
#printing the size
    #print(len(neutralWord))

#writing into file
#postive words
with codecs.open("positiveSentence","w","utf-8-sig") as file:
    for i in positiveWord:
        s=i.decode("utf-8")
        file.write(s)
        temp="\n"
        s=temp.decode("utf-8")
        file.write(s)
file.close()

#writing into file
#negative words
with codecs.open("negativeSentence","w","utf-8-sig") as file:
    for i in negativeWord:
        s=i.decode("utf-8")
        file.write(s)
        temp="\n"
        s=temp.decode("utf-8")
        file.write(s)
file.close()

#writing into file
#neutral words
with codecs.open("neutralSentence","w","utf-8-sig") as file:
    for i in neutralWord:
        s=i.decode("utf-8")
        file.write(s)
        temp="\n"
        s=temp.decode("utf-8")
        file.write(s)
file.close()
