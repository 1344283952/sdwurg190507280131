#include<iostream> 
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 5;
int n;
ll cit[MAXN],ge[MAXN],l = (ll)1e15,r,mid;
ll maxx(ll a,ll b)
{
	if(a > b) return a;
	return b;
}  
ll minn(ll a,ll b)
{
	if(a < b) return a;
	return b;
}  
bool cann(ll x)
{
	ll jl = ge[1] - x;
	for(int i = 2;i <= n;i ++)
		jl += cit[i - 1] - cit[i] + ge[i] - x;
	if(jl >= 0) return true;
	return false;
}
int main()
{
	scanf("%d",&n);
	for(int i = 1;i <= n;i ++)
	{
		scanf("%lld%lld",&cit[i],&ge[i]);
		r = maxx(r,ge[i]);
		l = minn(l,ge[i]);
	}
	while(r - l != 1)	
	{
		mid = (l + r) >> 1;
		if(cann(mid)) l = mid;
		else r = mid;
	}
	printf("%lld",l);
} 
