#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<dirent.h>

#define MAX_SIZE 1024

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
   printf("File needs to be created.\n");
   //Creating the file again
   fd = open(fileName,O_CREAT | O_WRONLY | O_TRUNC | O_APPEND,0777);
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



int main(int argc,char **argv){
    int status;
    struct stat st_buf;
    
    DIR *dir;
    struct dirent *ent;
    
    
    
    if ((dir = opendir (argv[1])) != NULL) {
      while ((ent = readdir (dir)) != NULL) {
       printf ("file name = %s\n", ent->d_name);
       status = stat (ent, &st_buf);
        char name[MAX_SIZE+5];
        strcpy(name,argv[1]);
        strcat(name,ent->d_name);
        int fr=openForRead(name); //the file opened for reading 
        if(fr>0) {
         printf ("%s is a regular file.\n",ent->d_name);
         printf("NEED to be copied.\n");
         printf("YES\n");
         char desPath[MAX_SIZE+5];
         strcpy(desPath,argv[2]);
         strcat(desPath,ent->d_name);
         int fw=openForWrite(desPath);
         int v = readFromFileWriteToFile(fr, fw);
         printf("Copied done.\n");
       }
       else {
         printf("%s is a directory.\n");
       }
     }
    }
    
     
}
