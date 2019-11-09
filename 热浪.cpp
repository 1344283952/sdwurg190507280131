#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAXN = 7000;
struct zt
{
	int f,t,v;
}road[MAXN<<1];
int first[MAXN],next[MAXN<<1],cnt = 0;
void build(int f,int t,int v)
{
	road[++ cnt] = (zt){f,t,v};
	next[cnt] = first[f];
	first[f] = cnt;
}
void init()
{
	memset(first,-1,sizeof(first));
	memset(next,-1,sizeof(next));
}
queue<int>q;
int use[MAXN],dis[MAXN];
void spfa(int s)
{
	memset(use,0,sizeof(use));
	memset(dis,0x3f,sizeof(dis));
	q.push(s);
	use[s] = true;
	dis[s] = 0;
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		use[u] = false;
		for(int i = first[u];i != -1;i = next[i])
		{
			int v = road[i].t ;
			if(dis[v] > dis[u] + road[i].v)
			{
				dis[v] = dis[u] + road[i].v ;
				if(!use[v])
					q.push(v);
				use[v] = 1;
			}
		}
	}
}
int main()
{
	init();
	int n,m,start,end;
	scanf("%d%d%d%d",&n,&m,&start,&end);
	for(int i  = 1;i <= m;i ++)
	{
		int f,t,v;
		scanf("%d%d%d",&f,&t,&v);
		build(f,t,v);
		build(t,f,v);
	}
	spfa(start);
	printf("%d",dis[end]);
}
