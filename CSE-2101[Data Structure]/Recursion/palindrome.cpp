#include <bits/stdc++.h>
using namespace std;
char arr[2000];

int palindrome(int low, int high) {
 if(low >= high) {
    return 1;
 }
 if(arr[low] != high) {
    return 0;
 }
 palindrome(low+1,high - 1);
}

int main()
{
   cin >> arr;
   int len;
   len = strlen(arr);
   int value = palindrome(0,len - 1);
   if(value == 0) {
    cout << "Not Palindrome" << endl;
   }
   if(value == 1) {
    cout << "Palindrome" << endl;
   }
   return 0;
}
