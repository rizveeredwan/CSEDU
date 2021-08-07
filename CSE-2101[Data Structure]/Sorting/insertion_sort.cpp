#include <bits/stdc++.h>
using namespace std;
void insertion_sort(int arr[20000], int n)
{
    int temp;
    for(int i = 1; i < n; i++)
    {
        if(arr[i] > arr[i+1])
        {
            temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
        }
    }
}
int main(void)
{
    int n,i,arr[20000];
    scanf("%d",&n);
    for(i = 1; i <= n; i++)
    {
        scanf("%d",&arr[i]);
        insertion_sort(arr,i);
    }
    for(i = 1; i <= n; i++)
    {
        printf("%d\n",arr[i]);
    }
    return 0;
}
