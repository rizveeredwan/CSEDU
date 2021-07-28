#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
 
int find;
pthread_t tid[10];
int ret1[10],ret2[10],ret3[10],ret4[10],ret5[10],ret6[10],ret7[10],ret8[10],ret9[10],ret10[10];
 
struct list
{
    int num;
    int index;
}; //struct of numbers and its position
 
/*int *search(struct list n[],int strt,int shesh)
{
    cnt=1;
    for(pos=strt; pos<=shesh; pos++)
    {
        if(n[pos].num == find)
        {
            ret1[cnt]=n[pos].index;
            cnt++;
            ret1[0]=cnt-1;
        }
        else printf("Not Found.\n");
    }
}*/
 
void* doSomeThing(void *arg)
{
    struct list *n=(struct array*)arg;
    pthread_t id=pthread_self();
 
    //for(i=0; i<(0xFFFFFFFF);i++);
   
    if(pthread_equal(id,tid[0]))
    {
        int pos;
        int cnt=1;
        // printf("First thread processing done\n");
        //ret1[10]=search(n,0,100);
        for(pos=0; pos<=100; pos++)
        {
            if(n[pos].num == find)
            {
                ret1[cnt]=n[pos].index;
                cnt++;
                ret1[0]=cnt-1;
            }
        }
        pthread_exit(&ret1);
    }
    else if(pthread_equal(id,tid[1]))
    {
        //printf("\n Second thread processing done\n");
        //ret2[10]=search(n,101,150);
        int pos;
        int cnt=1;
        for(pos=101; pos<=150; pos++)
        {
            if(n[pos].num == find)
            {
                ret2[cnt]=n[pos].index;
                cnt++;
                ret2[0]=cnt-1;
            }
        }
        pthread_exit(&ret2);
    }
    else if(pthread_equal(id,tid[2]))
    {
        //printf("3rd thread processing done\n");
        // ret3[10]=search(n,151,220);
        int pos;
        int cnt=1;
        for(pos=151; pos<=220; pos++)
        {
            if(n[pos].num == find)
            {
                ret3[cnt]=n[pos].index;
                cnt++;
                ret3[0]=cnt-1;
            }
        }
        pthread_exit(&ret3);
    }
    else if(pthread_equal(id,tid[3]))
    {
        //printf("4th thread processing done\n");
        //ret4[10]=search(n,221,423);
        int pos;
        int cnt=1;
        for(pos=421; pos<=423; pos++)
        {
            if(n[pos].num == find)
            {
                ret4[cnt]=n[pos].index;
                cnt++;
                ret4[0]=cnt-1;
            }
        }
        pthread_exit(&ret4);
    }
    else if(pthread_equal(id,tid[4]))
    {
        //printf("5th thread processing done\n");
        //ret5[10]=search(n,424,560);
        int pos;
        int cnt=1;
        for(pos=424; pos<=560; pos++)
        {
            if(n[pos].num == find)
            {
                ret5[cnt]=n[pos].index;
                cnt++;
                ret5[0]=cnt-1;
            }
        }
        pthread_exit(&ret5);
    }
    else if(pthread_equal(id,tid[5]))
    {
        //printf("6th thread processing done\n");
        //ret6[10]=search(n,561,620);
        int pos;
        int cnt=1;
        for(pos=561; pos<=620; pos++)
        {
            if(n[pos].num == find)
            {
                ret6[cnt]=n[pos].index;
                cnt++;
                ret6[0]=cnt-1;
            }
        }
        pthread_exit(&ret6);
    }
    else if(pthread_equal(id,tid[6]))
    {
        //printf("7th thread processing done\n");
        //ret7[10]=search(n,621,780);
        int pos;
        int cnt=1;
        for(pos=621; pos<=780; pos++)
        {
            if(n[pos].num == find)
            {
                ret7[cnt]=n[pos].index;
                cnt++;
                ret7[0]=cnt-1;
            }
        }
        pthread_exit(&ret7);
    }
    else if(pthread_equal(id,tid[7]))
    {
        //printf("8th thread processing done\n");
        //ret8[10]=search(n,781,840);
        int pos;
        int cnt=1;
        for(pos=781; pos<=840; pos++)
        {
            if(n[pos].num == find)
            {
                ret8[cnt]=n[pos].index;
                cnt++;
                ret8[0]=cnt-1;
            }
        }
        pthread_exit(&ret8);
    }
    else if(pthread_equal(id,tid[8]))
    {
        //printf("9th thread processing done\n");
        //ret9[10]=search(n,841,990);
        int pos;
        int cnt=1;
        for(pos=841; pos<=990; pos++)
        {
            if(n[pos].num == find)
            {
                ret9[cnt]=n[pos].index;
                cnt++;
                ret9[0]=cnt-1;
            }
        }
        pthread_exit(&ret9);
    }
    else if(pthread_equal(id,tid[9]))
    {
        //printf("10th thread processing done\n");
        //ret10[10]=search(n,991,999);
        int pos;
        int cnt=1;
        for(pos=991; pos<=999; pos++)
        {
            if(n[pos].num == find)
            {
                ret10[cnt]=n[pos].index;
                cnt++;
                ret10[0]=cnt-1;
            }
        }
        pthread_exit(&ret10);
    }
    return NULL;
}
 
int main()
{
    FILE *in,*out;
    int i,j,ran;
    
    struct list n[1001];
    in=fopen("random.txt","w"); //write in a file
 
    for(i=0; i<1000; i++)
    {
        //ran=rand();
        n[i].num=rand()%999+0; //random number generation
        n[i].index=i;
        fprintf(in,"%d: %d\n",n[i].index,n[i].num);
    }
 
    fclose(in);
 
    out=fopen("random.txt","r");//reading a file
    for(j=0; j<1000; j++)
    {
        fprintf(out,"%d: %d\n",n[j].index,n[j].num);
    }
    fclose(out);
 
    scanf("%d",&find);
    int err;
    int *ptr[10];
 
    for(i=0; i<10; i++)
    {
        err=pthread_create(&(tid[i]),NULL,&doSomeThing,&n);//create thread
        if(err!=0)
            printf("Can't create thread :[%s]\n", strerror(err));
        else
            printf("Thread number %d created successfully\n",i+1);
    }
    printf("Positions of %d :",find);
    for(i=0; i<10; i++)
    {
        pthread_join(tid[i],(void**)(&ptr[i])); //joining thread
        //printf(" return value from %d thread is [%d]\n",i, *ptr[i]);
            printf(" %d ",(ptr[i][0])); 
    }
    printf("\n");
    for(i = 0; i<10;i++) {
      if(ptr[i][0] != 0) {
       for(int nitu=1; nitu<=ptr[i][0]; nitu++) {
           printf("%d ",ptr[i][nitu]);
         }
      }
     }
     printf("\n");
 
    return 0;
}
