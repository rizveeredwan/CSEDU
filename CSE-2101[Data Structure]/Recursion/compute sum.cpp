#include <bits/stdc++.h>
using namespace std;

int sum(int n)
{
    if(n == 1)
    {
        return 1;
    }
    else
    {
      int value;
      value = n + sum(n - 1);
      return value;
    }
}
int main(void)
{
    int n;
    cin >> n;
    int answer = sum(n);
    cout << answer << endl;
    return 0;
}
