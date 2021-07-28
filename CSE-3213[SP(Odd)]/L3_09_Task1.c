#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

#define MAX_SIZE 1024

char buffer[MAX_SIZE+5];
char dir[MAX_SIZE+5];

//this function opens file for reading 
int openForRead(char fileName[]) {
   
  int fd = open(fileName,O_RDONLY);
  //success on opening file 
  if(fd>0) {
    return fd;
  } 
  else {
   //Error in opening the file 
   printf("Error in opening file\n");
   return -1;
  }
}

//this function opens file for writing 
int openForWrite(char fileName[]) {
  
  int fd = open(fileName,O_WRONLY | O_TRUNC | O_APPEND);
  if(fd>0) {
    //successful open operation
    return fd;
  }
  else {
   printf("File doesn't exist\n");
   //Creating the file again
   fd = open(fileName,O_CREAT | O_WRONLY | O_TRUNC | O_APPEND );
   if(fd>0) {
    //successful open operation
    return fd;
   }
   else {
    //successful open operation
    return fd;
   } 
  }
}

//This read from one file and write into another file 
int readFromFileWriteToFile(int fr, int fw) {
     int length;
     while((length=read(fr,buffer,MAX_SIZE))>0) {
        write(fw,buffer,length); 
     }
}

int closeFile(int f) {
  int v=close(f);
  if(v>0) return 1;
  else return -1;
}


int main(int argc, char **argv) {
  
   int fr=openForRead(argv[1]); //first file to be read 
   int path_len=strlen(argv[2]); // /home/student/....
   
   /*for(int i=path_len,j=0;j<=strlen(argv[1]);j++,i++) {
    argv[2][i] = argv[1][j];
   }*/
   
   int fw=openForWrite(argv[2]);
   int v = readFromFileWriteToFile(fr,fw);
   close(fr);
   close(fw);
   
}
