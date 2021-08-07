#include <bits/stdc++.h>
using namespace std;

int part(int a[1000], int start, int shesh)
{
    int pivot = a[shesh];
    int pivot_index = start,save,i;
    for(i = pivot_index; i < shesh; i++)
    {
        if(a[i] <= pivot)
        {
           int temp;
           temp = a[pivot_index];
           a[pivot_index] = a[i];
           a[i] = temp;
           pivot_index++;
        }
    }
    int temp;
    temp = a[pivot_index];
    a[pivot_index] = a[shesh];
    a[shesh] = temp;
    return pivot_index;
}


void quicksort(int a[1000], int start, int shesh)
{
  if(start < shesh)
  {
      int pivot_index = part(a,start,shesh);
      quicksort(a,start,pivot_index - 1);
      quicksort(a,pivot_index + 1, shesh);
  }
  //else return;
}

int main(void)
{
    int a[1000],n,i;
    scanf("%d",&n);
    for(i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }
    quicksort(a,0,n - 1);
    for(i = 0; i < n; i++)
    {
        printf("%d\n",a[i]);
    }
    return 0;


}
