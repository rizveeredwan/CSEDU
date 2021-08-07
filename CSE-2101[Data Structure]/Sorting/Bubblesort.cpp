#include <bits/stdc++.h>
using namespace std;
void bubble_sort(int arr[20000],int n)  //Ascending_Order
{
    int i,j,temp;
    for(i = 1; i < n; i++)
    {
        for(j = 1; j <= n - i; j++)
        {
            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(void)
{
   int n,arr[20000];
   scanf("%d",&n);
   for(int i = 1; i <= n; i++)
   {
       scanf("%d",&arr[i]);
   }
   bubble_sort(arr,n);
   for(int i = 1; i <= n; i++)
   {
       printf("%d\n",arr[i]);
   }
   return 0;
}
