#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int>a,sa;
int vt[1010];
int mx;
vector<int>g[1010];
void dfs(int u,int s)
{
	if(u==a.size()) return ;
	mx=max(mx,s);
	if(s+sa[u]<=mx) return ;
	for(int i=u;i<a.size();i++)
	{
		if(vt[i]) continue;
		vt[i]=1;
		for(auto v:g[a[i]]) vt[v]=1;
		dfs(i+1,s+a[i]);
		vt[i]=0;
		for(auto v:g[a[i]]) vt[v]=0;
	}
}
void solve()
{
	int n,x;
	cin>>n;
	set<int>st;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		mx=max(mx,x);
		st.insert(x);
	}
	for(auto i:st) a.push_back(i);
	
	sa.assign(a.size(),0);
	sa[a.size()-1]=a[a.size()-1];
	for(int i=a.size()-2;i>=0;i--) sa[i]=sa[i+1]+a[i];
	for(int i=0;i<a.size();i++)
	{
		for(int j=i+1;j<a.size();j++)
		{
			if(a[j]%a[i]==0)
			{
				g[a[i]].push_back(a[j]);
			}
		}
	}
	dfs(0,0);
	cout<<mx<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve();
}
