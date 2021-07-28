#!/bin/bash
cd $HOME/cs350-os161/os161-1.99
./configure --ostree=$HOME/cs350-os161/root --toolprefix=cs350-
cd kern/conf
./config ASST0
cd ../compile/ASST0

bmake depend
bmake
bmake install

cd $HOME/cs350-os161/os161-1.99
bmake
bmake install


cd $HOME/cs350-os161/root
cp $HOME/sys161/sys161.conf .

sys161 kernel-ASST0 
