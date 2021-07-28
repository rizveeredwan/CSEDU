# !/bin/bash
#this is my script 

echo "taken" 
echo "$1 $2 $3"
string=$3
cd $1
mkdir "AllFoundFiles"
for i in *.txt
do
  name=$i
  echo $name
  ok=grep -v string $i | wc -l
  echo $ok
  if[ ok > 1 ] ; then
   cat {$i} > "/home/student-08/AllFoundFiles"
  fi
done
