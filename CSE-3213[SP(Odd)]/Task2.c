#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<string.h>

#define BUFSIZE 10240
char buffer[10240];

int length;
int main(int argc,char **argv)
{
  
  printf("%d\n",argc);
  //taking input from terminal 
  for(int i=1;i<argc;i++)
  {
    printf("%s\n",argv[i]);
  }
  //output file writing
  int fd3 = open("c.txt",O_RDWR|O_TRUNC|O_APPEND);
  if(fd3<0)
  {
     printf("output file doesn't belong");
     fd3 = open("c.txt",O_CREAT);
     int error = close(fd3); 
     if(error<0)
     {
       printf("There is error\n");
     }
     else
     {
       fd3 = open("c.txt",O_RDWR|O_TRUNC|O_APPEND);
       if(fd3<0)
       {
         printf("Error in opening output file.\n");
       }
     }
  }
  printf("First reading from the end of the file.\n");
  for(int i=1;i<argc;i++)
  {
         int fd1 = open(argv[i],O_RDONLY);
         lseek(fd1, -8L, SEEK_END); 
         while ( (length = read (fd1, buffer, BUFSIZE)) > 0 )
         {
          //printf("length = %d\n",length);
          write (fd3, buffer, length); 
         } 
         close(fd1);
  }
  printf("First reading from the beginning of the file.\n");
  for(int i=1;i<argc;i++)
  {
         int fd1 = open(argv[i],O_RDONLY);
         length = read (fd1, buffer, 8);
         //printf("length = %d\n",length);
         write (fd3, buffer, length); 
         close(fd1);
  }
  close(fd3);
  fd3 = open("c.txt",O_RDONLY);
  //printf("%d\n",fd3);
  while ((length = read (fd3, buffer, BUFSIZE)) > 0 )
  {
     printf("%d\n",length);
     write (1, buffer, length); 
  } 
  close(fd3);
  return 0;
    
}
