#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 505;
const int M = 5e5 + 5;
struct zt
{
	int f,t;
}road[M];
int firs[N],used[N],nex[M],n,cnt = 0,t[N];
long long ans = 1e9,ma[N][N];
void build(int f,int t)
{
	road[++cnt] = (zt){f,t};
	nex[cnt] = firs[f];
	firs[f] = cnt;
}
void init()
{
	memset(firs,-1,sizeof(firs));
	memset(nex,-1,sizeof(nex));
}
int findd(int x)
{
	for(int i = firs[x];i != -1;i = nex[i])
	{
		int v = road[i].t;
		if(!used[v])
		{
			used[v] = 1;
			if(!t[v] || findd(t[v]))
			{
				t[v] = x;
				return 1;
			}
		}
	}
	return 0;
}
long long minn(long long a,long long b)
{
	if(a > b) return b;
	return a;
}
void xiyali()
{
	for(int i = 1;i <= n;i ++) 
	{
		memset(used,0,sizeof(used));
		findd(i);
	}	
}
int main()
{
	cin>>n;
	init();
	for(int i = 1;i <= n;i ++)
		for(int j = 1;j <= n;j ++)
		{
			cin>>ma[i][j];
			if(!ma[i][j]) continue;
			build(i,j);
		}
	xiyali();
	for(int i = 1;i <= n;i ++)
		if(t[i]) ans = minn(ans,ma[t[i]][i]);
	cout<<ans<<'\n';
} 
