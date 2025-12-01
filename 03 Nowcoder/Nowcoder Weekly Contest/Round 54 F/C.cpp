#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,t,mx,ans;
void solve()
{
	map<int,int>mp;
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
	{
		cin>>t;
		mp[t]++;
	}
	mx=mp[1];
    if(mx==0)
    {
        cout<<"0\n";
        return ;
    }
	ans=mx;
	for(int i=2;i<=n;i++)
	{
		if(!mp.count(i)) break;
		else mx=min(mx,mp[i]);
		ans+=mx;
	}
	cout<<ans<<'\n';
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
