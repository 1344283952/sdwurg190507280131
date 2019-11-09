#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 30000 + 5;
int prime[MAXN],non_prime[MAXN],cnt = 0;
void find_prime(int n)
{
	for(int i = 2;i <= n;i ++)
	{
		if(!non_prime[i]) prime[++cnt] = i;
		for(int j = 1;j <= cnt;j ++)
		{
			if(i * prime[j] > n) break;
			non_prime[i * prime[j]] = 1;
			if(i % prime[j] == 0) break;
		} 
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	find_prime(n);
	if(prime[cnt] == n) cout<<"\\"<<"t";
	else cout<<"\\"<<"n";
 } 
