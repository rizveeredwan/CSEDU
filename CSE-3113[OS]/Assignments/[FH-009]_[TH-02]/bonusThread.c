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

pthread_t ids[9]; //The id of the threads 
pthread_t special; //the special checking thread 
int ret[10]; //the value which will be returned 
int givenNumber; //the value which will be searched 
int repeat[1001]={0}; // for checking so that no value can be generated twice 
int alreadyGot=0; //the special flag 
int aliveThreads[10]={1}; //the threads which are alive till now 
int save; //the saved index of the thread which found the thread 
int luck= 11; //for looping 

void* searching(void *args) {
   
   temp = args; //capturing the address 
   
   pthread_t id = pthread_self(); //getting the id of the running thread 
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
		   alreadyGot = 1; 
		   save=i;
		   luck=0;
		   aliveThreads[i]=0;
	   }
     }
	 fclose(tempFile); 
	 int rt=i;
	 pthread_exit(&rt);
	 aliveThreads[i]=0;
	 printf("Thread %d is terminating.\n",i);
	 return NULL; 
   }
  }
   return NULL;
}

void* killingMyThreads(void *args) {

  pthread_t id = pthread_self();
  while(1) {
	if(alreadyGot==1) {
	  for(;luck<10;luck++) {
		 if(aliveThreads[luck]==1) {
			 printf("Thread %d is terminating.\n",luck);
			 pthread_cancel(ids[luck]);
			 aliveThreads[luck]=0; 
		  }  
	  }
	  break; 
	}  
  }	
  int rt=1;
  pthread_exit(&rt);
  return NULL;
}

int main(int argc, char **argv) {

   srand(time(NULL));  // the initialization of random function
   fp = fopen("input.txt","w"); //opening my file pointer
   for(int i=1;i<=1000;i++){
     int v = rand()%1000;
     if(repeat[v]==1) {
		i--;
		continue; 
     }
     repeat[v] = 1;
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
	 aliveThreads[i]=1; 
   }
   pthread_create(&(special),NULL,&killingMyThreads,NULL);
   for(int i=0;i<10;i++) { //creating threads 
	  pthread_create(&(ids[i]),NULL,&searching,NULL); 	 
   }
   pthread_join(special,(void**)(&p[0])); //the special joining thread  
   printf("Thread %d got the value at %d th position\n",threads[save].threadNumber,threads[save].arr[0]);
   return 0 ; //end of my program
}
