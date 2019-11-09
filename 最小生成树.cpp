#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX = 55000;
int n,ans = 0,cnt = 0,fa[MAX];
int c;
struct zt
{
	int f,t,v;
}road[MAX];
bool comp(zt a,zt b)
{
	return a.v < b.v;
}
int find(int x)
{
	if(x == fa[x])
		return fa[x];
	else
		return fa[x] = find(fa[x]);
}
int main()
{
	scanf("%d",&n);
	for(int i = 1;i <= n;i ++)
		fa[i] = i;
	for(int i = 1;i <= n;i ++)
		for(int j = 1;j <= n;j ++)
		{
			scanf("%d",&c);
			if(i >= j)
				continue;
			road[++cnt].v = c;
			road[cnt].f = i;
			road[cnt].t = j;
		}
	sort(road + 1,road + cnt + 1,comp);
	for(int i = 1;i <= cnt;i ++)
	{
		if(find(road[i].f) == find(road[i].t))
			continue;
		ans += road[i].v;
		fa[find(road[i].f)] = find(road[i].t);
	}
	printf("%d",ans);
}
