#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <sys/wait.h>
#include <string.h>


int func(char str[],char dis[]){
   int fd[100][2]; //file descriptors 
   int revFd[100][2];
   int collection[100];
   for(int i=0;i<100;i++) {
     pipe(fd[i]);
     pipe(revFd[i]);
   }
   int v = mkdir(dis,0777); //creating directory
   DIR *dir = opendir(str);
   int counter= -1;
   pid_t pid;
   if(dir != NULL) {
      int base = -1; 
      struct dirent *entry;
      while((entry = readdir(dir)) != NULL) {
         int down = 1;
         for(int i=0;i<strlen(entry->d_name);i++) {
             if(entry->d_name[i] == '.' && strlen(entry->d_name) <= 2) {
                down = 0;
                //printf("ase string = %s\n",entry->d_name);
                break;
             }
         }
         if(down == 0) {
           continue;
         }
         //printf("%s name %d\n",entry->d_name,strlen(entry->d_name));
         counter++;
         pid = fork();
         if(pid == 0) {
           close(fd[counter][1]);
           break;
         }
         else {
           collection[counter]=pid; 
           //parent will write 
           //(sr,des) format 
           
           //sr
           char temp[1024];
           strcpy(temp,str); 
           strcat(temp,entry->d_name);
           strcat(temp,"/");

           //dis 
           char temp2[1024];
           strcpy(temp2,dis);
           strcat(temp2,entry->d_name); 
           strcat(temp2,"/"); 
           
           //marge
           char pathabo[2048];
           strcpy(pathabo,temp);
           strcat(pathabo,",");
           strcat(pathabo,temp2);
 
           //the pipe data write 
           close(fd[counter][0]);
           write(fd[counter][1],pathabo,strlen(pathabo));
           //printf("%s %d\ counter = %d\n",pathabo,strlen(pathabo),counter);
           close(revFd[counter][1]);
           continue;          
         }      
      }
      if(pid == 0) {
        //the child task
        char receive[2048];
        int len;
        char get[1024];
        int ptr=0;
        while((len = read(fd[counter][0],get,8)) > 0) {
            for(int i=0;i<len;i++,ptr++) {
               receive[ptr] = get[i];
            }
            if(len<8){
              break;
            }
        }
        receive[ptr] = '\0'; 
        printf("shit = %s\n",receive);
        
        char des[1024];
        char matha[1024];
        int cnt = 0;
        int shu = 0;
        int ok=0;
        for(int i=0;i<strlen(receive);i++) {
           if(receive[i] == ',') {
              ok = 1;
              continue;
           }
           if(ok == 1) {
               des[cnt]=receive[i];
               cnt++;
           }
           if(ok == 0) {
              matha[shu]=receive[i];
              shu++;
           }
        }       
        des[cnt-1]='\0'; 
        matha[shu-1] = '\0'; 
        int fd = open(des,O_WRONLY,O_CREAT | O_TRUNC);
        int fr = open(matha,O_RDONLY,O_CREAT | O_TRUNC);
        
        printf("%s %s %d %d\n",des,matha,fd,fr);
        
        char buffer[1024];
        while((len=read(fr,buffer,8))>0) {
            write(fd,buffer,len);
        }        
        close(fd);
        close(fr);
        close(revFd[counter][0]);
        write(revFd[counter][1],"1",strlen("1"));
        //printf("done %d\n",counter);
        return 0; 
      }
      else {
         printf("break\n");
        //I am parent process 
           for(int i=0;i<=counter;i++) {
              char temp[1024];
              int len=read(revFd[i][0],temp,8);
           }
      }
   }
   
   
}

int main(int argc, char **argv) {
   func(argv[1],"/home/rizvee/keno/");  
}
