#include <bits/stdc++.h>
#define EPS 1e-9
using namespace std;
int main(void)
{
    int input,n;
    cin >> input >> n;
    double low = 0;
    double high  = input;
    double mid;
    int cnt = 0;
    while(cnt <= 70) {
    mid = (low +  high) / (2.0);
    double value = 1;
    for (int i = 1; i <= n; i++) {
    value = value  * mid * 1.0;
    }
    double diff = value - input;
    if(abs(diff) <= EPS) {
        break;
    }
    if(diff > 0) {
        high = mid;
    }
    if(diff < 0) {
        low = mid;
    }
    cnt++;
    }
    cout << mid << endl;
    return 0;
}
