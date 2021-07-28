#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


void openingFile(){
  /*this function opens a file
     int open (const char *name, int flags);
     int open (const char *name, int flags, mode_t mode);
     if ok return >=0
     else return -1
     flags= O_RDONLY,O_APPEND,O_CREAT,O_TRUNC,O_WRONLY can be ored
     modes=S_IRWXU, S_IRUSR,S_IWUSR,S_IXUSR
           S_IRGRP,S_IWGRP,S_IXGRP,S_IRWXG    
   */
   /*
      int fd = open(argv[1],O_RDONLY | O_WRONLY | O_TRUNC); 
    */
}
void creatingFile(){
  /*This function creates a file
     int creat (const char *name, mode_t mode);
     if ok returns >= 0
     else return -1 
  */
  /*
    int fd=creat(argv[1],O_WRONLY | O_TRUNC,S_IRWXU | S_IRWXG);  
   */
}
void readingFile(){
  /*
     This function reads from file 
     ssize_t read (int fd, void *buf, size_t len)
  */
  /*
    char buffer[1024];
    int length;
    while((length=read(fr,buffer,8))>0) {
      // length numbered bytes are read 
    }
  */
}
void writeFile(){
  /*this function writes into file
    ssize_t write (int fd, const void *buf, size_t count);
    if ok return >= 0
    else return -1  
  */
  /* 
   char buffer[1024];
    int length;
    while((length=read(fr,buffer,8))>0) {
       write(fw,buffer,length);  
    }
  */
}

void sync(){
  /*
   this function performs synchronized IO
   int fsync (int fd); -- write everything to disc 
   int fdatasync (int fd); --writes only the changed meta data
   void sync(void); //synchronizes everything 
   if -1 error
   else ok  
 */
}
void closing(){
   /*
     int close(int fd); 
     closing a file 
  */
}
void seeking(){
  /*
  off_t lseek (int fd, off_t pos, int origin);
  SEEK_CUR pos=0 present, pos>0 forward pos<0 backward 
  SEEK_END pos=0 end pos>0 after end pos<0 from back
  SEEK_SET pos=0 begin pos>0 move forward pos<0 move backward 
  if(not ok) returns -1   
  */ 
}

int main(int argc, char **argv){
  
}
