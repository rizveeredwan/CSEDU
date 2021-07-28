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
total=0
with open("negativeSentence", "r") as file:
    reader = file.readlines()
    for line in reader:
        # taking a line
        # splitting
        total = total+1
        if total>=500:
            break;
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
            j = i - 1
            while (j >= 0 and j >= i - windowSize):
                one = temporaryLine[i]
                two = temporaryLine[j]
                # taking all combinations
                data.append([one, two])
                j = j - 1
            i = i + 1
# pair taking is complete
# print(len(data))

# now need to make map
word = set(word)
for i, variable in enumerate(word):
    word2int[variable] = i
    int2word[i] = variable


# function to make indexing
def convertToOneHotVector(dataPointIndex, vocabularySize):
    temp = np.zeros(vocabularySize)  # 1 vector of vocabularySize * 1
    temp[dataPointIndex] = 1
    return temp;


# now input output word
x_train = [] # input word
y_train = [] # output word


i=0;
for dataWord in data:
    print("working")
    x_train.append(convertToOneHotVector(word2int[dataWord[0]],len(word)))
    y_train.append(convertToOneHotVector(word2int[dataWord[1]], len(word)))
    i=i+1
    #if(i>=5): #this is only for sanity testing
       # break; ######NEED TO BE COMMENTED######

print("done")
print(len(x_train))

# convert them to numpy arrays
# convert them to numpy arrays
x_train = np.asarray(x_train)
y_train = np.asarray(y_train)

#here starts calculation for Word 2 vectorss
# making placeholders for x_train and y_train
vocab_size = len(word)
x = tf.placeholder(tf.float32, shape=(None, vocab_size))
y_label = tf.placeholder(tf.float32, shape=(None, vocab_size))

#first hidden layer
EMBEDDING_DIM = 5 #The dimenstion to be checked must be 300
W1 = tf.Variable(tf.random_normal([vocab_size, EMBEDDING_DIM]))
b1 = tf.Variable(tf.random_normal([EMBEDDING_DIM])) #bias
hidden_representation = tf.add(tf.matmul(x,W1), b1)

#second output layer
W2 = tf.Variable(tf.random_normal([EMBEDDING_DIM, vocab_size]))
b2 = tf.Variable(tf.random_normal([vocab_size]))
prediction = tf.nn.softmax(tf.add( tf.matmul(hidden_representation, W2), b2))

#Training section
sess = tf.Session()
init = tf.global_variables_initializer()
sess.run(init) #make sure you do this!

# define the loss function:
cross_entropy_loss = tf.reduce_mean(-tf.reduce_sum(y_label * tf.log(prediction), reduction_indices=[1]))

# define the training step:
train_step = tf.train.GradientDescentOptimizer(0.1).minimize(cross_entropy_loss)

n_iters = 100 #the number of iterations

# train for n_iter iterations
for _ in range(n_iters):
    sess.run(train_step, feed_dict={x: x_train, y_label: y_train})

######After calculation#########
vectors = sess.run(W1 + b1)
#The prediction vector

#writing into file
#words along with vectors
with codecs.open("negativeVector","w","utf-8-sig") as file:
    for i in word:
        #writing the word
        string = i.decode("utf-8")
        file.write(string)
        string = "\n"
        string = string.decode("utf-8")
        file.write(string)
        mappedNumber = word2int[i] #the mapped number
        mappedVector = vectors[mappedNumber] #the mapped vector
        j=0
        while j<EMBEDDING_DIM:
            value=mappedVector[j]
            file.write(str(value))
            file.write("\n")
            j=j+1
        #string = "\n"
        string = string.decode("utf-8")
        #file.write(string)
file.close()










