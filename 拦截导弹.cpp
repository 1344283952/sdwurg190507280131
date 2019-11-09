#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 25;
int cnt = 0,ans = 0,missile[MAXN],dp[MAXN],device[MAXN],ji; 
int main()
{
	while(scanf("%d",&missile[++cnt]) == 1)
	{
		for(int i = 1;i <= cnt;i ++)
			if((!device[i]) || device[i] >= missile[cnt])
			{
				device[i] = missile[cnt];
				break;
			}
	}
	for(int i = 1;;i ++)
		if(!device[i])
		{
			ji = i - 1;
			break;
		}
	for(int i = 1;i <= cnt;i ++)
	{
		dp[i] = 1;
		for(int j = 1;j < i;j ++)
			if(missile[i] <= missile[j])
				dp[i] = max(dp[i],dp[j] + 1);
		ans = max(dp[i],ans);
	}
	printf("%d\n%d",ans - 1,ji);
}
