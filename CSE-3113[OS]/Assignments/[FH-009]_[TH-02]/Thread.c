#include<stdio.h>
#include<time.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>

FILE *fp; //Global file pointer 

struct info{
	
	int threadNumber; //name of the thread 
	int low,high; // low pointer from the file reading will begin and high pointer to where the file reading will stop
	int *arr; // where I will save the indexes the positions 
	int counter; // the array size
	int searchValue; // the value which will be searched
}threads[10],*temp; 

pthread_t ids[9];
int ret[10];
int givenNumber;

void* searching(void *args) {
   
   temp = args; //capturing the address 
   
   pthread_t id = pthread_self();
   for(int i=0;i<10;i++) {
   if(pthread_equal(ids[i],id)) { //this thread only will work when it will get valid thread positions 
	 
	 FILE *tempFile = fopen("input.txt","r"); //opening the file for this thread 
	 int filePointer= (threads[i].low-1)*4; //calculating the pointer 
	 fseek(tempFile,filePointer,SEEK_SET); //setting the pointer 
	 for(int j= threads[i].low ;j<= threads[i].high;j++) { //looping through the position
	   int v;
	   fscanf(tempFile,"%d",&v); //taking the input 
	   if(v==threads[i].searchValue) { //if matches setting the value in the array 
		   threads[i].arr[threads[i].counter]=j;
		   threads[i].counter++;
	   }
     }
	 fclose(tempFile); 
	 int rt=i;
	 pthread_exit(&rt);
	 return NULL; 
   }
  }
   return NULL;
}

int main(int argc, char **argv) {

   srand(time(NULL));  // the initialization of random function
   fp = fopen("input.txt","w"); //opening my file pointer
   for(int i=1;i<=1000;i++){
     int v = rand()%1000;
     fprintf(fp,"%3d\n",v); // it's actually for (0 to 999) to make everyone three character size including space if needed
   }
   fclose(fp); //closing file pointer
   
   //initialization of the threads 
   int start = 0;
   srand(time(NULL)); 
   for(int i=0;i<10;i++) { //randomly generating the thread  searching  windows 
	    start++; 
	    threads[i].arr=malloc(sizeof(int)); 
	    threads[i].low = start;
	    threads[i].counter=0;
	    threads[i].threadNumber = i;
	    int v = rand()%100+start;
	    threads[i].high=v; 
	    start = v;
   } 
   threads[9].high=1000;
   
   int *p;  //for getting the return value 
   
   printf("please give the input number to search : ");
   scanf("%d",&givenNumber); 
   
   for(int i=0;i<10;i++) {
	 threads[i].searchValue=givenNumber;   
   }
   
   for(int i=0;i<10;i++) { //creating threads 
	  pthread_create(&(ids[i]),NULL,&searching,NULL); 	 
   }
   for(int i=0;i<10;i++) { //joining threads 
	  pthread_join(ids[i],(void **)(&p[0]));  	 
   }
   for(int i=0;i<10;i++) {   
      if(threads[i].counter != 0) {
		  for(int j=0;j<threads[i].counter; j++) {
			printf("%d ",threads[i].arr[j]);   
		  }
	  }
   }
   printf("\n");
   return 0 ; //end of my program
}
