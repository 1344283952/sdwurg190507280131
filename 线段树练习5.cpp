#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN = 4e5;
struct zt
{
	ll l,r,sum,sz,jia,cnt,MAX,MIN;
	zt *lift,*right;
};
zt tree[MAXN];
ll m,n,a,b,c,cnt = 0,ji;
string s;
void build(zt *root,ll l,ll r)
{
	root->sum = 0;root->l = l;root->r = r;root->MAX = 0;root->MIN = 0;
	root->sz = r - l + 1;root->jia = 0;root->cnt = -1;
	if(l == r)	return;
	root->lift = &tree[++cnt];
	root->right = &tree[++cnt];
	ll mid = (l + r)>>1;
	build(root->lift,l,mid);
	build(root->right,mid + 1,r);
}
void xf_cnt(zt *root)
{
	root->lift->cnt = root->cnt;
	root->right->cnt = root->cnt;
	root->lift->sum = root->cnt * root->lift->sz;
	root->right->sum = root->cnt * root->right->sz;
	root->lift->MAX = root->cnt;
	root->right->MAX = root->cnt;
	root->lift->MIN = root->cnt;
	root->right->MIN = root->cnt;
	root->lift->jia = 0;
	root->right->jia = 0;
	root->cnt = -1;
}
void xf_jia(zt *root)
{
	root->lift->jia += root->jia;
	root->right->jia += root->jia;
	root->lift->sum += root->jia * root->lift->sz;
	root->right->sum += root->jia * root->right->sz;
	root->lift->MAX += root->jia;
	root->right->MAX += root->jia;
	root->lift->MIN += root->jia;
	root->right->MIN += root->jia;
	root->jia = 0;
}
void add(zt *root,ll l,ll r,ll ql,ll qr,ll x)
{
	if(l >= ql&&qr >= r)
	{
		root->sum += root->sz * x;
		root->MAX += x;
		root->MIN += x;
		root->jia += x;
		return;
	}
	if(root->cnt != -1)	xf_cnt(root);
	if(root->jia)	xf_jia(root);
	ll mid = l + r>>1;
	if(ql <= mid)	add(root->lift,l,mid,ql,qr,x);
	if(qr > mid)	add(root->right,mid + 1,r,ql,qr,x);
	root->MAX = max(root->lift->MAX,root->right->MAX);
	root->MIN = min(root->lift->MIN,root->right->MIN);
	root->sum = root->lift->sum + root->right->sum;
}
void set(zt *root,ll l,ll r,ll ql,ll qr,ll x)
{
	if(l >= ql&&qr >= r)
	{
		root->sum = root->sz * x;
		root->cnt = x;
		root->jia = 0;
		root->MAX = x;
		root->MIN = x;
		return;
	}
	if(root->cnt != -1)	xf_cnt(root);
	if(root->jia)	xf_jia(root);
	ll mid = l + r>>1;
	if(ql <= mid)	set(root->lift,l,mid,ql,qr,x);
	if(qr > mid)	set(root->right,mid + 1,r,ql,qr,x);
	root->MAX = max(root->lift->MAX,root->right->MAX);
	root->MIN = min(root->lift->MIN,root->right->MIN);
	root->sum = root->lift->sum + root->right->sum;
}
ll find(zt *root,ll l,ll r,ll ql,ll qr)
{
	if(l >= ql&&qr >= r)
	{
		if(s == "sum")	return root->sum;
		if(s == "max")	return root->MAX;
		if(s == "min")	return root->MIN;
	}
	if(root->cnt != -1)	xf_cnt(root);
	if(root->jia)	xf_jia(root);
	ll ans = 0,mid = l + r >>1,ma = -1e15,mi = 1e15;
	if(s == "sum")
	{
		if(ql <= mid)	ans += find(root->lift,l,mid,ql,qr);
		if(qr > mid)	ans += find(root->right,mid + 1,r,ql,qr);
	}
	else if(s == "max")
	{
		ans = ma;
		if(ql <= mid)	ans = find(root->lift,l,mid,ql,qr);
		if(qr > mid)	ans = max(find(root->right,mid + 1,r,ql,qr),ans);
	}
	else if(s == "min")
	{
		ans = mi;
		if(ql <= mid)	ans = find(root->lift,l,mid,ql,qr);
		if(qr > mid)	ans = min(find(root->right,mid + 1,r,ql,qr),ans);
	}
	return ans;
}
int main()
{
	scanf("%lld %lld",&n,&m);
	build(tree,1,n);
	for(ll i = 1;i <= n;i ++)
	{
		scanf("%lld",&a);
		add(tree,1,n,i,i,a);
	}
	for(int i = 1;i <= m;i ++)
	{
		cin>>s;
		if(s == "add"||s == "set")
		{
			scanf("%lld %lld %lld",&a,&b,&c);
			if(s == "add")	add(tree,1,n,a,b,c);
			else	set(tree,1,n,a,b,c);
		}
		else
		{
			scanf("%lld %lld",&a,&b); 
			cout<<find(tree,1,n,a,b)<<'\n';
		}
	}
}
