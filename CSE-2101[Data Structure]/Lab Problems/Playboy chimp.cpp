//PLAYBOY CHIMP


#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    long long int n,q,i,arr[50010],que[25010],index_value,low,high,mid,find_lower,find_higher,maxAns,minAns;
    cin >> n;
    for(i = 1; i <= n; i++) {
    cin >> arr[i];
    }
    cin >> q;
    for(i = 1; i <= q; i++) {
        cin >> que[i];
    }
    for(i = 1; i <= q; i++) {
       index_value = que[i];
       low = 1;
       high = n;
       find_lower = 0;
       find_higher = 0;
       maxAns = arr[n]+1;
       minAns= arr[1] - 1;
      // cout << maxAns << " " << minAns << endl;
       while(1) {
        mid = (low + high) / 2.0;
        //cout << " mid = " << arr[mid] << endl;
        if(low > high) {
           break;
        }
        if(arr[mid] > index_value) {
            if(arr[mid] != index_value) {
               find_higher = 1;
               maxAns = min(arr[mid],maxAns);
              // cout << maxAns << " lol " << endl;
            }
           high = mid - 1;
        }
        if(arr[mid] <= index_value) {
            low = mid + 1;
        }
    }
    low = 1;
    high = n;
    while(1) {
        mid = (low + high) / 2;
       // cout << " mid = " << arr[mid] << endl;
        if(low > high) {
            break;
        }
        if(arr[mid] < index_value) {
            if(arr[mid] < index_value) {
                find_lower = 1;
                minAns = max(arr[mid],minAns);
               // cout << minAns << " hi " << endl;
            }
            low = mid + 1;
        }
        if(arr[mid] >= index_value) {
            high = mid - 1;
        }
    }
    if(find_lower == 0) {
        printf("X ");
    }
    else {
        printf("%lld ",minAns);
    }
    if(find_higher == 0) {
        printf("X\n");
    }
    else {
        printf("%lld\n",maxAns);
    }
    }
    return 0;
}

