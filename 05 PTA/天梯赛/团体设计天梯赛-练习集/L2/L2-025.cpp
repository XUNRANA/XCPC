#include <bits/stdc++.h>
using namespace std;
#define int long long


void solve()
{
	int n,m,u,v,k,x,q;
	cin>>n>>m;
	vector<pair<int,int>>a;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v;
		a.push_back({u,v});
	}
	cin>>q;
	while(q--)
	{
		cin>>k;
		set<int>st;
		while(k--)
		{
			cin>>x;
			st.insert(x);
		}
		int f=0;
		for(auto i:a)
		{
			u=i.first;
			v=i.second;
			if(!st.count(u)&&!st.count(v))
			{
				f=1;
				break;
			}
		}
		if(f) cout<<"NO\n";
		else cout<<"YES\n";
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

