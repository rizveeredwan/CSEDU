#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>

#define MAX 1024 
#define MAX_LEN 100000

char searchKey[MAX+5];
int thresh;
char folder[MAX+5];
char finaldir[MAX+5];


int openFileRead(char *argv){
  int fd = open(argv,O_RDONLY);
  return fd;  
}
int openFileWrite(char *argv) {
  int fr = open(argv,O_WRONLY | O_TRUNC);
  if(fr == -1) {
    fr=creat(argv,O_WRONLY | O_TRUNC | S_IRWXU); 
    return fr; 
  }
}
void saveBuffer(int fd, char *sec) {
  int length;
  char buffer[MAX_LEN+5];
  read(fd,buffer,MAX_LEN); 
  //printf("%s\n",buffer); 
  int counter=0;
  for(int i=0;i<strlen(buffer);i++) {
     if(buffer[i] == searchKey[0]) {
       int ok=1;
       int j=0;
       for(j=0; j<strlen(searchKey) && (i+j)<strlen(buffer); j++) {
         if(buffer[i+j] == searchKey[j]) {
           ok=1;
           continue;
         }
         else {
          ok=0;
          break;
         }
       }
       if(ok == 1) {
        i=i+j;
        counter++;
      
       }
     }
  }
  if(counter >= thresh) {
    int fr = openFileWrite(sec);
    printf("%d\n",fr);
    write(fr,buffer,strlen(buffer));
    printf("%s\n",sec);
    close(fr);
    close(fd);
    printf("likhsi.\n");
  }
}

void readDirectory(char *src, char *des){
    DIR *dir;
    dir = opendir(src);
    struct dirent *entry;
    while((entry = readdir(dir)) != NULL) {
       int len;
       char test[MAX+5];
       strcpy(test,src);
       strcat(test,entry->d_name);
       //printf("%s\n",test);
       len=strlen(test);
       if(test[len-1] == 't' && test[len-2] == 'x'  && test[len-3] == 't'  && test[len-4]=='.') {
          int fd = openFileRead(test);
          printf("%d %s\n",fd,test);
          if(fd != -1) {
           char sec[MAX+5];
           strcpy(sec,des);
           strcat(sec,entry->d_name);
           saveBuffer(fd,sec);
          }
       }
    }
}

int main(int argc, char **argv) {
   strcpy(searchKey,argv[1]);
   thresh=0;
   for(int i=0;i<strlen(argv[2]);i++) {
     thresh = thresh * 10 + (argv[2][i]-'0');
   }
   char *cwd;
   cwd = get_current_dir_name();
   printf("%s\n",cwd);
   strcpy(folder,cwd);
   if(cwd[strlen(cwd)-1] != '/') {
    strcat(folder,"/");
   }
   strcat(folder,argv[3]);
   if(argv[3][strlen(argv[3])-1] != '/'){ 
   strcat(folder,"/");
   }
   strcat(finaldir,cwd);
   if(cwd[strlen(cwd)-1] != '/') {
    strcat(finaldir,"/");
   }
   strcat(finaldir,"AllFoundFiles/");
   int v = mkdir(finaldir,01777);
   readDirectory(folder,finaldir);
   
   printf("Search key = %s\n threshold = %d\n, folder = %s\n",searchKey,thresh,folder);
   return 0;
}
