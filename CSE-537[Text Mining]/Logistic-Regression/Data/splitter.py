f = open('marks.txt', "r")
line = f.readlines()

o = open("save.txt", "w")
count = 0
for i in line:
    count = count+1
    s = i.split(" ")
    t = s[4].split('\r\n')
    print (t, count)
    o.write(t[0])
    o.write("\n")
o.close()
