#include <bits/stdc++.h>
using namespace std;
int phi(int n)//Å·À­º¯Êý 
{
	int res=n;
	for(int p=2;p*p<=n;p++)
	{
		if(n%p==0)
		{
			while(n%p==0) n/=p;
			res-=res/p;
		}
	}
	if(n>1) res-=res/n;
	return res;
}

void solve()
{
	int n;
	cin>>n;
	long long ans=0;
	for(int d=1;d*d<=n;d++) 
	{
		if(n%d==0)
		{
			ans+=d*phi(n/d);
			if(d!=n/d) ans+=(n/d)*phi(d);
		}
	}
	cout<<ans<<"\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
