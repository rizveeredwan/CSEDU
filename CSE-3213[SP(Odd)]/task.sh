# !bin/bash
echo "my script"
cnt=0
for i in *.txt
do
 name[$((++cnt))]=$i
 echo ${name[1]} 
done 
echo "Give your choice"
read input
cat ${name[$input]}

