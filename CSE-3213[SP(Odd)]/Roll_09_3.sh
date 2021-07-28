# !bin/bash
echo "my script"
read directory
cd $directory
cnt=0
for i in *.txt
 do
  echo "$((++cnt)). $i"
 done
