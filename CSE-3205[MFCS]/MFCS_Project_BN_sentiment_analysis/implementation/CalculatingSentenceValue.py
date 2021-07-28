import codecs
import GeneralWord2Vec as general
import math
import numpy as np

# EMBEDDING_DIM or feature vector
EMBEDDING_DIM = 5

# reading vectors from file along with words
# positive words
positiveWord = []
positiveWordNumber = {}
positiveWordVector = []

# neutral words
neutralWord = []
neutralWordNumber = {}
neutralWordVector = []

# negative words
negativeWord = []
negativeWordNumber = {}
negativeWordVector = []


def readFromFile(fileName):
    checkWordNumber = {}
    checkWordVector = []
    checkWord = []

    # print("ase")
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

    # print(len(checkWord))
    if fileName == "positiveVector":
        length = len(checkWord)
        i = 0
        while i < length:
            positiveWord.append(checkWord[i])
            positiveWordVector.append(checkWordVector[i])
            i = i + 1
        i = 0
        for word in positiveWord:
            positiveWordNumber[word] = i
            i = i + 1
    elif fileName == "negativeVector":
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
    elif fileName == "neutralVector":

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

            # print("done for "+ " " + str(fileName))


# reading from files
# function call
readFromFile("positiveVector")
readFromFile("negativeVector")
readFromFile("neutralVector")


# single word and type will be given
# this function will return the type of word vector for this word
def returnSingleVector(word, type):
    checkWordNumber = []
    checkWordVector = {}
    checkWord = []

    if type == 0:
        checkWordNumber = positiveWordNumber
        checkWordVector = positiveWordVector
        checkWord = positiveWord
    elif type == 1:
        checkWordNumber = negativeWordNumber
        checkWordVector = negativeWordVector
        checkWord = negativeWord
    elif type == 2:
        checkWordNumber = neutralWordNumber
        checkWordVector = neutralWordVector
        checkWord = neutralWord

    if word in checkWord:
        number = checkWordNumber[word]
        return checkWordVector[number]

    else:
        tempVector = []
        i = 0
        while i < EMBEDDING_DIM:
            tempVector.append(1.0)
            i = i + 1
        return tempVector;


def returnSentenceVectors(sentence, type):
    vector = []
    line = sentence.split()
    for word in line:
        vector.append(returnSingleVector(word, type))
    return vector


def vectorMultiplication(sentence, type):
    # sentence=testing sentence
    # type=which type of vector we need
    vector = returnSentenceVectors(sentence, type)
    ans = 0
    i = 0
    j = 0
    # print(vector[0][1]*vector[1][3])
    while i < EMBEDDING_DIM:
        length = len(vector)
        # print(length)
        j = 0
        temp = 1
        while j < length:
            temp = temp * vector[j][i]
            j = j + 1
        i = i + 1
        ans = ans + temp
    # print("yes")
    return ans


# answer vectors

inputLines = []
positive = []
negative = []
neutral = []
realVerdict = []
secondVerdict = []

# reading input lines and saving verdict
# first Algorithm
with open("InputLines") as file:
    reader = file.readlines()
    counter = 0
    for line in reader:
        if counter == 1:
            counter = 0
            realVerdict.append(line)
            continue

        # print(line)
        ans1 = vectorMultiplication(line, 0)
        ans2 = vectorMultiplication(line, 1)
        ans3 = vectorMultiplication(line, 2)
        # print("positive = " + str(ans1) + " negative " + str(ans2) + " neutral " + str(ans3))
        inputLines.append(line)
        positive.append(ans1)
        negative.append(ans2)
        neutral.append(ans3)
        counter = 1
file.close()


# second Algorithm part
def vectorDifference(vector1, vector2):
    i = 0
    ans = 0
    while i < EMBEDDING_DIM:
        ans = ans + (vector1[i] - vector2[i]) * (vector1[i] - vector2[i])
        i = i + 1
    ans = math.sqrt(ans)
    return ans


def decision(pos, neg, neu, base):
    posDiff = vectorDifference(pos, base)
    negDiff = vectorDifference(neg, base)
    neuDiff = vectorDifference(neu, base)

    minimum = min(posDiff, negDiff, neuDiff)

    if (posDiff < negDiff and posDiff < neuDiff):
        return "positive"
    if (negDiff < posDiff and negDiff < neuDiff):
        return "negative"
    return "neutral"


def function(sentence, vector):
    line = sentence
    line = line.split()

    i = 0
    po = 0
    ne = 0
    nu = 0
    for var in line:
        pos = returnSingleVector(var, 0)
        neg = returnSingleVector(var, 1)
        neu = returnSingleVector(var, 2)
        string = decision(pos, neg, neu, vector[i])

        i = i + 1

        if (string == "positive"):
            po = po + 1

        elif (string == "negative"):
            ne = ne + 1

        elif (string == "neutral"):
            nu = nu + 1

    if (po > ne and po > nu):
        return "positive"
    if (ne > po and ne > nu):
        return "negative"
    return "neutral"


# reading input lines and saving verdict(second Algorithm)
with open("InputLines") as file:
    reader = file.readlines()
    counter = 0
    for line in reader:
        if counter == 1:
            counter = 0
            continue
        else:
            word2vec = general.functionToCalculate(line)
            secondVerdict.append(function(line, word2vec))
            counter = 1

# Third Algorithm

thirdVerdict = []

data = []
WINDOW_SIZE = 2


def euclidean_dist(vec1, vec2):
    return np.sqrt(np.sum((vec1 - vec2) ** 2))


def find_closest(word_index, vectors):
    min_dist = 10000  # to act like positive infinity
    min_index = -1
    query_vector = vectors[word_index]
    for index, vector in enumerate(vectors):
        if euclidean_dist(vector, query_vector) < min_dist and not np.array_equal(vector, query_vector):
            min_dist = euclidean_dist(vector, query_vector)
            min_index = index
    return min_index


with open("InputLines") as file:
    reader = file.readlines()
    counter = 0
    for line in reader:

        cnt0 = 0
        cnt1 = 0
        cnt2 = 0
        sum = 0

        if counter == 1:
            counter = 0
            continue
        else:
            sentence = []
            sentence.append(line.split())

            i = 0;
            while i < len(sentence[0]):
                j = i + 1
                while j < len(sentence[0]) and j <= i + WINDOW_SIZE:
                    data.append([sentence[0][i], sentence[0][j]])
                    j += 1
                i += 1

            for pair in data:

                dis0 = 1000000000
                dis1 = 1000000000
                dis2 = 1000000000

                if pair[0] in positiveWord and pair[1] in positiveWord:
                    pos0 = returnSingleVector(pair[0], 0)
                    pos1 = returnSingleVector(pair[1], 0)

                    pos0 = np.asarray(pos0)
                    pos1 = np.asarray(pos1)

                    dis0 = euclidean_dist(pos0, pos1)

                if pair[0] in negativeWord and pair[1] in negativeWord:
                    neg0 = returnSingleVector(pair[0], 1)
                    neg1 = returnSingleVector(pair[1], 1)

                    neg0 = np.asarray(neg0)
                    neg1 = np.asarray(neg1)

                    dis1 = euclidean_dist(neg0, neg1)

                if pair[0] in neutralWord and pair[1] in neutralWord:
                    neu0 = returnSingleVector(pair[0], 2)
                    neu1 = returnSingleVector(pair[1], 2)

                    neu0 = np.asarray(neu0)
                    neu1 = np.asarray(neu1)

                    dis2 = euclidean_dist(neu0, neu1)

                mn = 1000000000
                mn = min(mn, dis0)
                mn = min(mn, dis1)
                mn = min(mn, dis2)

                if (dis0 == mn):
                    cnt0 += 1
                elif (dis1 == mn):
                    cnt1 += 1
                else:
                    cnt2 += 1

            counter = 1

        if (cnt0 >= cnt1 and cnt0 >= cnt2):
            thirdVerdict.append("positive")
            # print("pos")
        elif (cnt1 >= cnt0 and cnt1 >= cnt2):
            thirdVerdict.append("negative")
            # print("neg")
        else:
            thirdVerdict.append("neutral")
            # print("neu")

# wrting in file:
length = len(inputLines)
with codecs.open("result", "w", "utf-8-sig") as file:
    i = 0

    cnt1 = 0
    cnt2 = 0
    cnt3 = 0

    while i < length:
        string = inputLines[i]
        string = string  # creates problem in python2 otherwise
        file.write(string.decode("utf-8"))

        # common for both files
        '''file.write("positive = " + str(positive[i]) + "\n")
        file.write("negative = " + str(negative[i])+"\n")
        file.write("neutral = " + str(neutral[i])+"\n")'''
        file.write("real verdict = " + str(realVerdict[i]))
        value1 = abs(positive[i])
        value2 = abs(negative[i])
        value3 = abs(neutral[i])
        result = min(value1, value2)
        result = min(result, value3)
        answer = ""
        if (result == value1):
            answer = "positive"
        if (result == value2):
            answer = "negative"
        if (result == value3):
            answer = "neutral"
        file.write("Hypothesis 1 verdict = " + answer + "\n")
        file.write("Hypothesis 2 verdict = " + str(secondVerdict[i]) + "\n")
        file.write("Hypothesis 3 verdict = " + str(thirdVerdict[i]) + "\n")

        if (answer[2] == realVerdict[i][2]):
            cnt1 += 1

        if (secondVerdict[i][2] == realVerdict[i][2]):
            cnt2 += 1

        if (thirdVerdict[i][2] == realVerdict[i][2]):
            cnt3 += 1

        i = i + 1

    print(str(cnt1) + " " + str(cnt2) + " " + str(cnt3))
