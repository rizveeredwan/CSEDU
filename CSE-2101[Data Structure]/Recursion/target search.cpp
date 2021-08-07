#include <bits/stdc++.h>
using namespace std;
int arr[2000];

int bs(int low, int high, int point)
{
    if(low > high) {
        return 0;
    }
    int mid = (low+high)/2;
    cout << "mid = " << mid << "low = " << low << " " << "high = " << high << " " << arr[mid] << endl;
    if(arr[mid] == point)
    {
        cout <<"ase" << endl;
        return 1;
    }
    if(arr[mid] > point)
    {
        cout << "ase 1" << endl;
        return bs(low,mid-1,point);
    }
    if(arr[mid] < point)
    {
        cout << "ans 2" << endl;

        return bs(mid+1,high,point);
    }

}
int main(void)
{
    int n;
    cin >> n;
    int i,input;
    cout << "Array must be sorted" << endl;
    cout <<"Now please give inputs " << endl;
    for(i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    cout << "Now give input to  make query " << endl;
    cin >> input;
    int value = bs(1,n,input);
    cout << "value = " << value << endl;
    if(value == 1)
    {
        cout << "The input is found in the array" << endl;
    }
    if(value == 0)
    {
        cout << "The input is not found in the array" << endl;
    }
    return 0;
}
