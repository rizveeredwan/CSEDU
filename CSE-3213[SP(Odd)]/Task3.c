#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<string.h>

#define BUFSIZE 102400 

char buffer[BUFSIZE+5];
char test[BUFSIZE+5]; 
int length;
int pos[BUFSIZE+5];

int main(int argc, char **argv)
{
   printf("%d\n",argc);
   
   int fd1 = open(argv[1],O_RDONLY);
   int sizeFile=0;
   while ((length = read (fd1, buffer, BUFSIZE)) > 0)
   {
      
   }
   int counter= -1;
   for(int i=0;i<strlen(buffer);i++)
   {
       if((i+strlen(argv[2]))<strlen(buffer)) {
          int ok= 0;
          for(int j=0;j<strlen(argv[2]);j++)
          {
             if(buffer[i+j] == argv[2][j])
             {
               ok=1;
               continue;
             }
             else
             {
               ok=0;
               break;
             }
          }
          if(ok)
          {
             counter++;
             pos[counter] = i;
             continue;
          }
       }
       
   }
   for(int i=0;i<=counter;i++)
   {
     if((i+1)>counter)
     {
       for(int j=pos[i],guni=1;j<strlen(buffer) && guni<=100; guni++,j++)
       {
         printf("%c",buffer[j]);
       }
       break;
     }
     else
     {
       for(int j=pos[i],guni=1;j<strlen(buffer) && guni<=100; guni++,j++)
       {
         if(j == pos[i+1]) break;
         printf("%c",buffer[j]);
       }
     }
   }
   return 0;
   
}
