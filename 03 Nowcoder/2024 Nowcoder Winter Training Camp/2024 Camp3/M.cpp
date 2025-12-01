#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,t,ans;
int a[100010];
void solve()
{
	cin>>n;
	map<int,int>mp[2];
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		a[i]=t;
		if(t<10) ans+=mp[0][36-t];
		else 
		{
			if(t%36==0) ans+=mp[1][0];
			else ans+=mp[1][36-t%36];
		}	
		mp[0][t%36*10%36]++;
		mp[1][t%36*28%36]++;
	}
	mp[0].clear();
	mp[1].clear();
	for(int i=n;i>=1;i--)
	{
		t=a[i];
		if(t<10) ans+=mp[0][36-t];
		else 
		{
			if(t%36==0) ans+=mp[1][0];
			else ans+=mp[1][36-t%36];
		}	
		mp[0][t%36*10%36]++;
		mp[1][t%36*28%36]++;
	}
	cout<<ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
