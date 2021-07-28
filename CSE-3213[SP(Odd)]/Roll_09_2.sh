# !bin/bash
echo "my script"
cnt=0
for i in *.txt
do
  echo "$((++cnt)).  $i"
done 
