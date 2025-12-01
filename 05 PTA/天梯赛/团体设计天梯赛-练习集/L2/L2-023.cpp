#include <bits/stdc++.h>
using namespace std;
int c[510];
void solve()
{
	int n,e,k;
	cin>>n>>e>>k;
	set<pair<int,int>>a;
	for(int i=1;i<=e;i++)
	{
		int u,v;
		cin>>u>>v;
		if(u>v) swap(u,v);
		a.insert({u,v});
	}
	int t;
	cin>>t;
	while(t--)
	{
		set<int>cnt;
		for(int i=1;i<=n;i++) 
		{
			cin>>c[i];
			cnt.insert(c[i]);
		}
		if(cnt.size()!=k) 
		{
			cout<<"No\n";
			continue;
		}
		int f=0;
		for(auto i:a)
		{
			int u=i.first;
			int v=i.second;
			if(c[u]==c[v])
			{
				cout<<"No\n";
				f=1;
				break;
			}
		}
		if(!f) cout<<"Yes\n";
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

