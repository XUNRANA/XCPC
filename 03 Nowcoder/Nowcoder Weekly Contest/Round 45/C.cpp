#include <bits/stdc++.h>
using namespace std;
#define int long long
int f(int x)
{
	int res=0;
	while(x)
	{
		res+=x%10;
		x/=10;
	}
	return res;
}

void solve()
{
	int n;
	cin>>n;
	map<int,int>mp;
	for(int i=1;i<=n;i++)
	{
		int t=f(i);
		if(t&1) continue;
		if(t<i) 
		{
			if(mp.count(t)) mp[i]=1;
		}
		else mp[i]=1;
	}
	cout<<mp.size();
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
