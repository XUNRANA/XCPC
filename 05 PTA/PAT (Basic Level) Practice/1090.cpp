#include <bits/stdc++.h>
using namespace std;
#define int long long

set<int>g[100010];
int n,m,u,v,k,x;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>u>>v;
		g[u].insert(v);
		g[v].insert(u);
	}
	while(m--)
	{
		cin>>k;
		set<int>st;
		int f=0;
		while(k--)
		{
			cin>>x;
			for(auto v:g[x])
			{
				if(st.count(v))
				{
					f=1;
					break;
				}
			}
			st.insert(x);
		}
		if(f) cout<<"No\n";
		else cout<<"Yes\n";
	}
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}
