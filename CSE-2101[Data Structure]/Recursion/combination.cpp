#include <bits/stdc++.h>
using namespace std;

int combination(int n, int k)
{
    if(n == 0)
    {
        return 0;
    }
    if(k == 0)
    {
        return 1;
    }
    if(k == 1)
    {
        return n;
    }
    int value = combination(n-1,k) + combination(n - 1,k - 1);
    return value;
}

int main()
{
    int n,k;
    cin >> n >> k;
    int value = combination(n,k);
    cout << value << endl;
    return 0;
}
