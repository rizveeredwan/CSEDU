#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <pthread.h>
pthread_t tid[10];
int range[] = {61,123,345,420,533,698,725,800,888,999};//the ith number in the array is the ending index of ith thread(0 based indexing ; i = 0 - 9)
int ar[10][4];
int found;//as a boolean for terminatins the threads
void* linear_search(int n) //the function searches for the numbers in the thread
{
	pthread_t id = pthread_self(); // stores the id of the thread in id
	int i,j;
	for(i = 0;i<10;i++)
	{
        if(pthread_equal(id,tid[i])) //checks whether the id matches which the thread running
        {

            ar[i][0] = 0;
            if(found==1)//found=1 denotes the number has already been found
            {
                ar[i][0] = 0;
                printf("Thread no %d terminated before search began\n",i);
                pthread_exit(&ar[i]);
            }
            int start = 0,end = 0;
            if(i!=0)start = range[i-1]+1; //ith thread will start searching the (1 + ending index of (i-1)th thread)
            end = range[i]; //the ith thread will end searing in this defined range
            FILE *fp = fopen("rand.txt","r");//the file is opened for searching
            fseek(fp,start*4,SEEK_SET);//SEEK_SET is the starting of the file pointed by fp , the offset is set to (start*4) as each line holds 4 bytes : 3 for the digits as characters, 1 for "\n"
            int cnt = 0; //cnt will be used for counting the number of times n occurs in the range searched by the current thread
            for(j = start;j<=end;j++)
            {
                if(found==1)
                {
                    printf("Thread no. %d terminated with %d numbers left to search.\n",i,end-j-1);
                    ar[i][0] = 0;
                    pthread_exit(&ar[i]);
                }

                int x;
                fscanf(fp,"%d",&x);
                if(x==n)
                {
                    ar[i][0] = 1;
                    printf("Found the number in thread no. %d\n",i);
                    ar[i][1] = j;//0 based indexing
                    found = 1 ;
                    break;
                }
            }
            fclose(fp);
            pthread_exit(&ar[i]);//pthread_exit terminates the current thread and returns the value from ar[i]
        }
    }
	return NULL;
}
int main()
{
    srand(time(NULL));//using time a seed for generating random values
    int i,j,n,err;//i ,j as a counter for loops, n for the input, err for checking error in thread creation
    int *ans[10];//for storing the answers from 10 different threads
    FILE *fo = fopen("rand.txt","w");//fo is pointer for file "rand.txt"

    for(i = 0;i<1000;i++)
    {
        int x = rand()%1000;//for generating a integer from 0 to 999
        fprintf(fo,"%3d\n",x);//using %3d so that it occupies the space for exactly 3 characters
    }
    fclose(fo);
	printf("Enter the number to search:\n");
	scanf("%d",&n);
	for(i=0;i<10;i++)
    {
        void* num= (void*)n;//for typecasting the number as (void*)
        err = pthread_create(&(tid[i]), NULL, &linear_search, num);//pthread_chreate creates a new thread
        if(err != 0)//err = 0 means no error
        {
            printf("Can't create thread\n");
        }
    }

    for(i = 0;i<10;i++)
    {
        pthread_join(tid[i], (void**)&(ans[i]));//the value passed to pthread_exit() by the terminating thread shall be made available in the location referenced by ans[i]

        int k = *ans[i]; // used the 0th index for holding the number of instances
        for(j = 1;j <=k;j++) // the address refered by (ans[i]+ j) holds the value of ar[i][j] where j = 1 to number of instances
            printf("Instance found from %dth thread. Index = %d\n",i,*(ans[i]+j));

    }
    return 0;
}
