# !bin/bash
echo "my script"
cnt=0
for i in *
do
  echo "$((++cnt)).  $i"
done 

