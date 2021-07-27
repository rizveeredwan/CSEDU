#include<bits/stdc++.h>
using namespace std;

int price[25],weight[25];
int dp[25][200];

int func(int n,int k)
{
	if(k>100) return -100000000;
	if(n>10) return 0;
	if(dp[n][k] != -1) return dp[n][k];
	int weight = max(price[n]+func(n+1,k+arr[i]),func(n+1,k));
	dp[n][k]=weight;
	return dp[n][k];
}

int main(void)
{
	memset(dp,-1,sizeof(dp));
	
	int value = func(1,0);
	cout<<value<<endl;
}
