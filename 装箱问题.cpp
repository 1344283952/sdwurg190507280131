#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 20000 + 10;
int dp[MAXN],wp[35],v,ans = 0,n;
int main()
{
	scanf("%d%d",&v,&n);
	for(int i = 1;i <= n;i ++)	scanf("%d",&wp[i]);
	for(int i = 1;i <= n;i ++)
		for(int j = v;j >= wp[i];j --)
			dp[j] = max(dp[j],dp[j - wp[i]] + wp[i]);
	printf("%d",v - dp[v]); 
}
