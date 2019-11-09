#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 2e4 + 5;
const int MAXM = 1e5 + 5;
int n,m,fa[MAXN],di[MAXN];
bool ok = 0;
struct zf
{
	int a,b,c;
}cri[MAXM]; 
void init()
{
	for(int i = 1;i <= n;i ++) fa[i] = i;
}
bool com(zf a,zf b)
{
	return a.c > b.c;
}
int find(int a)
{
	if(fa[a] == a) return a;
	return fa[a] = find(fa[a]);
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i = 1;i <= m;i ++)
		scanf("%d %d %d",&cri[i].a,&cri[i].b,&cri[i].c);
	init();	
	sort(cri + 1,cri + m + 1,com);
	for(int i = 1;i <= m;i ++)
	{
		if(find(cri[i].a) == find(cri[i].b))
		{
			printf("%d",cri[i].c);
			ok = 1;
			break;
		}
		if(!di[find(cri[i].a)]) di[find(cri[i].a)] = find(cri[i].b);
		if(!di[find(cri[i].b)]) di[find(cri[i].b)] = find(cri[i].a);
		fa[find(cri[i].a)] = find(di[cri[i].b]);
		fa[find(cri[i].b)] = find(di[cri[i].a]);
	}
	if(!ok) puts("0");
} 
