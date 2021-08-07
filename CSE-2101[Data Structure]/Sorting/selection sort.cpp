#include <bits/stdc++.h>
using namespace std;
void selection_sort(int arr[20000], int n) // ascending order
{
    int i,j,temp;
    for(i = 1; i <= n; i++)
    {
        for(j = i + 1; j <= n; j++)
        {
            if(arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
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
   selection_sort(arr,n);
   for(int i = 1; i <= n; i++)
   {
       printf("%d\n",arr[i]);
   }
   return 0;
}
