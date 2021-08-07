#include <bits/stdc++.h>
using namespace std;

void merge_e_guchano(int A[100],int LeftA[100],int RightA[100],int sizeA, int sizeLeftA, int sizeRightA)
{
    int i = 0,j = 0,k = 0;
    while(i < sizeLeftA && j < sizeRightA)
    {
        if(LeftA[i] <= RightA[j])
        {
            A[k] = LeftA[i];
            i++;
            k++;
        }
        else
        {
            A[k] = RightA[j];
            j++;
            k++;
        }
    }
    while(i < sizeLeftA)
    {
        A[k] = LeftA[i];
        i++;
        k++;
    }
    while(j < sizeRightA)
    {
        A[k] = RightA[j];
        j++;
        k++;
    }
    printf("sort korar por\n");
    for(i = 0; i < k; i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
}
void mergesort(int A[100],int sizeA)
{
    if(sizeA < 2)
    {
        return ;
    }
    int LeftA[100];
    int RightA[100];
    int sizeLeftA = sizeA/2;
    int sizeRightA = sizeA - sizeLeftA;
    int i,j;
    for(i = 0; i < sizeLeftA; i++)
    {
        LeftA[i] = A[i];
        printf("%d ",LeftA[i]);
    }
    printf("\n");
    for(i = 0,j = sizeLeftA; j < sizeA; j++,i++)
    {
        RightA[i] = A[j];
        printf("%d ",RightA[i]);
    }
    printf("\n");
    mergesort(LeftA,sizeLeftA);
    mergesort(RightA,sizeRightA);
    merge_e_guchano(A,LeftA,RightA,sizeA,sizeLeftA,sizeRightA);

}

int main(void)
{
    int n,arr[100],i;
    scanf("%d",&n);
    for(i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    mergesort(arr,n);
    for(i = 0; i < n; i++)
    {
        printf("%d\n",arr[i]);
    }
}
