#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

#define MAX_SIZE 1024

char buffer[MAX_SIZE+5];


int main(int argc,char **argv) {
  
  int v=rename(argv[1],argv[2]);
  return 0;
}
