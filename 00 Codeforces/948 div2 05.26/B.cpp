#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[32];
void solve()
{
	cin>>n;
	for(int i=0;i<=31;i++)
	{
		if(n>>i&1) a[i]=1;
		else a[i]=0;
	}
	int f=0;
	for(int i=0;i<=31;i++) 
	{
		if(f)
		{
			if(a[i]==0) 
			{
				if(a[i+1]==1) a[i]=-1;
				else a[i]=1,f=0;
			}
			else a[i]=0;
			continue;
		}
		if(a[i]==1)
		{
			if(a[i+1]==1)
			{
				a[i]=-1;
				f=1;
			}
			else continue;
		}
	}
	cout<<32<<"\n";
	for(int i=0;i<=31;i++) cout<<a[i]<<" ";
	cout<<"\n";
}

signed main()
{

	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
