//POINTS IN SEGMENTS


#include <bits/stdc++.h>
using namespace std;

long long int flag;
long long int bs_one(long long int arr[], long long int n,long long int value) {
 long long int low = 1, high = n , mid, counter = 0,save = -1;
 while(1) {
    mid = (low + high) / 2;
    if(low > high) break;
    /*if(low == high) {
        mid = low;
        if(arr[mid] <= value) {
        save = max(save,mid);
    }
    break;
    } */
    if(arr[mid] <= value) {
      save = max(save,mid);
    }
    if(arr[mid] > value) {
        high = mid - 1;
    }
    if(arr[mid] <= value) {
      low = mid + 1;
    }
    //if(low == high) break;
 }
 return save;
}
long long int bs_two(long long int arr[], long long int n,long long int value) {
 long long int low = 1, high = n, mid, counter = 0,save = -1,f = 0;
 while(1) {
    mid = (low + high) / 2;
   // cout << arr[mid] << " " << mid << endl;
    if(low > high) break;
    /*if(low == high) {
        mid = low;
       if(arr[mid] <= value) {
       if(arr[mid] == value) {
       if(f == 1) save = min(save,mid);
       if(f == 0) {
        save = mid;
        f = 1;
       }
       }
       if(arr[mid] < value) {
        save = max(save,mid);
       }
    }
    break;
    } */
    if(arr[mid] <= value) {
       if(arr[mid] == value) {
       if(f == 1) save = min(save,mid);
       if(f == 0) {
        save = mid;
        f = 1;
       }
       flag = 1;
       }
       if(arr[mid] < value) {
        save = max(save,mid);
       }
    }
    if(arr[mid] > value) {
        high = mid - 1;
    }
    if(arr[mid] <= value) {
      low = mid + 1;
    }
    //if(low == high) break;
 }
 return save;
}

int main(void)
{
   long long int T,t,n,q,arr[100100],i,start,shesh,low,high,mid,counter,v1,v2;
   scanf("%lld",&T);
   for(t = 1; t <= T; t++) {
   scanf("%lld %lld",&n,&q);
   for(i = 1; i <= n; i++) {
    scanf("%lld",&arr[i]);
   }
   printf("Case %lld:\n",t);
   for(i = 1; i <= q; i++) {
     scanf("%lld %lld",&start,&shesh);
    // printf("%lld %lld\n",start,shesh);
     flag = 0;
      v1 = bs_one(arr,n,shesh);
  //  cout << v1 << endl;
     v2 = bs_two(arr,n,start);
   // cout << v2 << endl;
     if(v1 == -1) {
        v1 = 0;
        v2 = 0;
     }
     if(v2 == -1) {
        v2 = 0;
     }
     //cout << flag << endl;
     printf("%lld\n",v1 - v2 + flag);
   }

   }
   return 0;
}

