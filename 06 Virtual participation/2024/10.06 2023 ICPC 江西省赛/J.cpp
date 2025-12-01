#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,x,q,op,a,b,ans;
void solve()
{
	cin>>n;
	map<int,int>mp;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		mp[i]=x;
	}
	cin>>q;
	while(q--)
	{
		cin>>op;
		if(!op)
		{
			cin>>a>>b;
			if(mp.count(a)) mp[a]=min(mp[a],b);
			else mp[a]=b;
		}
		else
		{
			cin>>a;
			ans=1e18;
			if(mp.count(a)) ans=min(ans,mp[a]);
			for(int i=1;i;i++)
			{
				if(i*i+1>=ans) break;
				if(mp.count(a+i)) ans=min(ans,i*i+mp[a+i]);
				if(mp.count(a-i)) ans=min(ans,i*i+mp[a-i]);
			}
			cout<<ans<<"\n";
		}
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
