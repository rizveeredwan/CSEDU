#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int arr[100],manush,counter;
    int n,k,i;
    scanf("%d %d",&n,&k);
    for(i = 1; i <= n; i++)
    {
        arr[i] = 1;
    }
    manush = n;
    counter = 0;
    for(i = 1; i <= n && manush != 1; i++)
    {
        if(arr[i] == 1 && counter == k)
        {

            arr[i] = 0;
            counter = 0;
            manush = manush - 1;
            if(i == n)
            {
                i = 0;
            }

        }
        else if(arr[i] == 1 && counter < k)
        {
            counter++;
            if(i == n)
            {
                i = 0;
            }
        }
        if(i == n)
        {
            i = 0;
        }


    }
    for(i = 1; i <= n; i++)
    {
        if(arr[i] == 1)
        {
            printf("%d\n",i);
        }
    }
    return 0;
}
