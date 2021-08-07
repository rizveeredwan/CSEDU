#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int arr[1000];
    int n,i,j;
    int counterarr[1000];
    memset(counterarr,0,sizeof(counterarr));
    scanf("%d",&n);
    for(i = 0; i < n; i++)
    {
       scanf("%d",&arr[i]);
       int v = arr[i];
       counterarr[v] = counterarr[v] + 1;
    }
    for(i = 0; i < 100; i++)
    {
        if(counterarr[i] != 0)
        {
            int v = counterarr[i];
            for(j = 1; j <= v ; j++)
            {
                printf("%d ",i);
            }
        }
    }

    printf("\n");
    return 0;
}
