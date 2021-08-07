#include <bits/stdc++.h>
using namespace std;

int main(void)
{
      double low = 0;
      double high = 2000;
      double t = 0;
      double mid,value;
      double jack = 60;
      while(1)
      {
          mid = (low + high) / (2.0);
          t = mid / 100;
          value = jack * t;
          double sum = value + mid;
          if(abs(sum - 2000) <= 1e-9) {
            break;
          }
          if(sum <  2000) {
            low = mid;
          }
          if(sum > 2000) {
            high = mid;
          }
    }
    cout << "They met at " << t << " time" << endl;
    cout << "jack crossed distance = " << value << endl;
    cout << "Jill crossed distance = " << mid << endl;
    return 0;
}
