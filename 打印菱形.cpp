#include<iostream> 
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
int main()
{
	cin>>n;
	for(int i = 1;i <= n;i ++)
	{
		for(int j = i;j < n;j ++) cout<<" ";
		for(int j = 1;j <= 2 * i - 1;j ++)
		{
			if(j == 1||j == 2 * i - 1) cout<<"+";
			else cout<<"*";
		}
		puts("");
	}
	for(int i = n - 1;i >= 1;i --)
	{
		for(int j = i;j < n;j ++) cout<<" ";
		for(int j = 1;j <= 2 * i - 1;j ++)
		{
			if(j == 1||j == 2 * i - 1) cout<<"+";
			else cout<<"*";
		}
		puts("");
	}
}
