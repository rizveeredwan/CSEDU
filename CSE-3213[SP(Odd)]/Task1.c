#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<string.h>

#define BUFSIZE 10240

int fd1,fd2,fd3;
int length;
char buffer[BUFSIZE+5];

int main(int argc, char **argv)
{

  printf("%d\n",argc);
  //taking input from terminal 
  for(int i=1;i<argc;i++)
  {
    printf("%s\n",argv[i]);
  }
  //open file 
  fd1 = open(argv[1],O_RDONLY);
  fd2 = open(argv[2],O_RDONLY);
  fd3 = open("c.txt",O_RDWR|O_TRUNC|O_APPEND);
  //sanity for fd3
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
  if(fd1<0)
  {
    printf("File1 does not belong\n");
    printf("Give input from console\n");
    scanf("%s",buffer);
    buffer[strlen(buffer)]='\n';
    buffer[strlen(buffer)+1]='\0';
    write(fd3,buffer,strlen(buffer));
  }
  else
  {
       while ( (length = read (fd1, buffer, BUFSIZE)) > 0 )
       {
          write (fd3, buffer, length); 
       }
       printf("Write one done complete\n");
      
  }
  if(fd2<0)
  {
    printf("File2 does not belong\n");
    printf("Give input from console\n");
    scanf("%s",buffer);
    buffer[strlen(buffer)]='\n';
    buffer[strlen(buffer)+1]='\0';
    write(fd3,buffer,strlen(buffer));
  }
  else
  {
       while ( (length = read (fd2, buffer, BUFSIZE)) > 0 )
       {
          write (fd3, buffer, length); 
       }
       printf("Write Two done complete\n");
  }
  close(fd3);
  printf("Printing from the file.\n");
  fd3 = open("c.txt",O_RDONLY);
   while ( (length = read (fd3, buffer, BUFSIZE)) > 0 )
   {
          write (1, buffer, length); 
   }
  
  return 0;
}
