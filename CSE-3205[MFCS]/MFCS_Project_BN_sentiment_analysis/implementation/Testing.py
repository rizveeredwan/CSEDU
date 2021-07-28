# reading line and calculation of word2vec
# reading from file

# header files
import numpy as np
import tensorflow as tf
import codecs

# common words to save
word = []
# pair wise selection
data = []
# window size
windowSize = 2
# word2Vec mapping in word2vec
word2int = {};
int2word = {};
# file reading
with open("positiveSentence", "r") as file:
    reader = file.readlines()
    for line in reader:
        # taking a line
        # splitting
        line = line.split()
        # taking each word
        temporaryLine = []
        for temp in line:
            word.append(temp)
            temporaryLine.append(temp)  # saving this line word by word
        # print(len(temporaryLine))
        # using the window and and make pair word by word
        length = len(temporaryLine)
        i = 0
        while i < length:
            j = i + 1
            while (j < length and j <= i + windowSize):
                one = temporaryLine[i]
                two = temporaryLine[j]
                # taking all combinations
                data.append([one, two])
                j = j + 1
            i = i + 1
# pair taking is complete
# print(len(data))

# now need to make map
word = set(word)
print(len(word))
print(len(data))