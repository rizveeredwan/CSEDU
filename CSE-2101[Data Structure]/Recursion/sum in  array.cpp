#include <bits/stdc++.h>
using namespace std;

int arr[1000];

int sum(int start,int len)
{
    int ans;
    if(start == len) {
        return arr[start];
    }
    ans = arr[start] +sum(start+1,len);
    return ans;
}
int main(void)
{
   int n;
   cin >> n;
   int i;
   for(i = 1; i <= n; i++) {
    cin >> arr[i];
   }
   int value = sum(1,n);
   cout << value << endl;
   return 0;

}
