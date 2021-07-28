#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>

#define USING  104
#define MAX_LEN 1024
int MAX_SIZE = 1024;

char buffer[MAX_LEN+5];
char base[MAX_LEN*10+5];
int  idx[MAX_LEN*10+5];

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

void* increaseSize(char *argv)
{
  char *newSize = realloc(argv, MAX_SIZE * sizeof(char));
  if(newSize) {
    argv=newSize;
    MAX_SIZE = MAX_SIZE + 1024;
    return argv;
  }
}

int main(int argc, char **argv)
{
   //The testing string 
   char test[MAX_SIZE+5];
   strcpy(test,argv[2]);
   //open file for reading 
   int fr = openForRead(argv[1]);
   int length;
   //Reading complete
   while(length=read(fr,buffer,USING)) {
     if((length+strlen(base))>= MAX_SIZE) {
       increaseSize(base);
     }
     strcat(base,buffer); 
   }
   //now save the index
   int counter=-1;
   for(int i=0;i<strlen(base);i++) 
   {
       if(base[i] == test[0]) {
          int ok=1;
          for(int j=0;j<strlen(test) && (i+j)<strlen(base) ; j++) {
             if(base[i+j] == test[j]) {
                continue;
             }
             else {
               ok = 0;
               break;
             } 
         }
         if(ok) {
           counter++;
           idx[counter]=i;
           continue;          
         }
       }
   }
   //now checking
   for(int i=0;i<=counter;i++) {     
    if((i+1)<=counter) {
       for(int j=idx[i]+strlen(test),guni=1;guni<=100;j++,guni++) {
           if(j>=idx[i+1]) break;
           else {
             printf("%c",base[j]);
           }
       }
    }
    else {
       for(int j=idx[i]+strlen(test),guni=1;guni<=100;j++,guni++) {
           if(j>=strlen(base)) break;
           else {
             printf("%c",base[j]);
           }
       }
    }
   } 
   printf("\n");  
   return 0;      
}

