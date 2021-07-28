#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

#define MAX_SIZE 1024
char FileName[MAX_SIZE+5];
char buffer[MAX_SIZE+5];


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
int readFromFileWriteToFileByByteFront(int fr, int fw, int k, char *argv) {
     int length;
     length = read(fr,buffer,k);
     FileName[0]='f';
     FileName[1]='r';
     FileName[2]='o'; 
     FileName[3]='n';
     FileName[4]='t';
     FileName[5]=' ';
     int len = strlen(argv);
     int i,j=0;
     for(i=6,j=0;j<len;j++,i++) {
      FileName[i]=argv[j];
     }
     FileName[i] = ':';
     FileName[i+1]='\0';
     write(fw,FileName,sizeof(FileName));
     write(fw,buffer,length);    
     char File[5];
     File[0] = '\n';
     File[1] = '\0';
     write(fw,File,sizeof(File));
     return 1;
} 

//This read from one file and write into another file 
int readFromFileWriteToFileByByteBack(int fr, int fw, int k, char *argv) {
     int length;
     lseek(fr,-k,SEEK_END); 
     length = read(fr,buffer,k);
     FileName[0]='B';
     FileName[1]='a';
     FileName[2]='c'; 
     FileName[3]='k';
     FileName[4]=' ';
     int len = strlen(argv);
     int i,j=0;
     for(i=5,j=0;j<len;j++,i++) {
      FileName[i]=argv[j];
     }
     FileName[i] = ':';
     FileName[i+1]='\0';
     write(fw,FileName,sizeof(FileName));
     write(fw,buffer,length);    
     char File[5];
     File[0] = '\0';
     write(fw,File,sizeof(File));
     return 1;
} 

int closeFile(int f) {
  int v=close(f);
  if(v>0) return 1;
  else return -1;
}


int main(int argc, char **argv)
{
   printf("Give input how many bytes you want to read\n");
   int k;
   scanf("%d",&k);
   int fw=openForWrite("c");    
   for(int i=1;i<argc;i++) {
       int fr = openForRead(argv[i]);
       if(fr>0) {
         readFromFileWriteToFileByByteFront(fr,fw,k,argv[i]);        
         close(fr);
       }
       else {
           printf("Wrong input file name in %dth term\n",i);
       }
   }
   for(int i=1;i<argc;i++) {
       int fr = openForRead(argv[i]);
       if(fr>0) {
         readFromFileWriteToFileByByteBack(fr,fw,k,argv[i]);        
         close(fr);
       }
       else {
           printf("Wrong input file name in %dth term\n",i);
       }
   }
   close(fw);
}
