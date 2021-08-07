#include <bits/stdc++.h>
using namespace std;

char arr[100];

void string_reverse(int shuru, int shesh, int length)
{
   if(shuru >= shesh) {
    cout << arr;
   }
   else
   {
       char temp;
       temp = arr[shuru];
       arr[shuru] = arr[shesh];
       arr[shesh] = temp;
       string_reverse(shuru+1,shesh-1,length);
   }
}

int main(void)
{
   cin >> arr;
   int len = strlen(arr);
   string_reverse(0,len-1,len);
   return 0;
}
