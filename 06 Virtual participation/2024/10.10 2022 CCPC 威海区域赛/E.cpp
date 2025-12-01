#include <bits/stdc++.h>
using namespace std;
int a[100010];
int n,k;
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		if(a[i]<k)
		{
			printf("Python 3.%d will be faster than C++",i);
			return ;
		}
	}
	for(int i=n+1;i;i++)
	{
		a[i]=max(0,2*a[i-1]-a[i-2]);
		if(a[i]>=a[i-1])
		{
			printf("Python will never be faster than C++");
			return ;
		}
		else if(a[i]<k)
		{
			printf("Python 3.%d will be faster than C++",i);
			return ;
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
