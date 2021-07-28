#!/bin/bash
tar -xzf os161-binutils.tar.gz
cd binutils-2.17+os161-2.0.1

./configure --nfp --disable-werror --target=mips-harvard-os161 --prefix=$HOME/sys161/tools

make || find . -name '*.info' | xargs touch ; make
make install

mkdir $HOME/sys161/bin

cd ~
echo export PATH=$HOME/sys161/bin:$HOME/sys161/tools/bin:$PATH >> .bashrc
echo export PATH=$HOME/sys161/bin:$HOME/sys161/tools/bin:$PATH >> .bash_profile

reboot
