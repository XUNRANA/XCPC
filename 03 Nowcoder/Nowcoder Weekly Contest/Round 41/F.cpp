#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,l,r,u,v,mx,f[100010],vt[100010],ans[100010];
string s;
vector<int>g[100010];
vector<int>idx;
void dfs(int u,int fa)
{
	f[u]=fa;
	for(auto v:g[u])
	{
		if(v==fa) continue;
		dfs(v,u);
	}
}

void dfs1(int u,int fa)
{
	vt[u]=1;
	for(auto v:g[u])
	{
		if(v==fa) continue;
		dfs1(v,u);
	}
	idx.push_back(u);
}
void solve()
{
	cin>>n>>l>>r>>s;
	s=" "+s;
	vector<pair<int,int>>a(n);
	for(int i=1;i<n;i++)
	{
		cin>>u>>v;
		a[i]={u,v};
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0);
	for(int i=1;i<=n;i++) g[i].clear();
	for(int i=1;i<n;i++)
	{
		u=a[i].first;
		v=a[i].second;
		if(s[u]=='R'&&s[v]=='R') continue;
		if(s[u]=='W'&&s[v]=='R'&&f[v]==u) continue;
		if(s[v]=='W'&&s[u]=='R'&&f[u]==v) continue;
		g[u].push_back(v);
		g[v].push_back(u);
	}

    if(s[1]=='R')
    {
        idx.clear();
        dfs1(1,-1);
		int res=0;
		ans[idx[0]]=l;
		res+=l;
		for(int j=1;j<idx.size();j++)
		{
			if(res<0) ans[idx[j]]=r;
			else ans[idx[j]]=l;
			res+=ans[idx[j]];
		}
		
		if(res>0)
		{
			for(auto j:idx) 
			if(ans[j]>0) 
			{
				ans[j]-=res;
				break;
			}
		}
		else if(res<0)
		{
			for(auto j:idx) 
			if(ans[j]<0) 
			{
				ans[j]-=res;
				break;
			}
		}
    }
    else
    {
        idx.clear();
        dfs1(1,-1);
        for(auto j:idx) 
        if(r>-l) ans[j]=r;
        else ans[j]=l;
    }
    
	for(int i=2;i<=n;i++) 
	{
		if(vt[i]) continue;
		idx.clear();
		dfs1(i,-1);
		int res=0;
        ans[idx[0]]=l;
        res+=ans[idx[0]];
        
		for(int j=1;j<idx.size();j++)
		{
			if(res<0) ans[idx[j]]=r;
			else ans[idx[j]]=l;
			res+=ans[idx[j]];
		}
		
		if(res>0)
		{
			for(auto j:idx) 
			if(ans[j]>0) 
			{
				ans[j]-=res;
				break;
			}
		}
		else if(res<0)
		{
			for(auto j:idx) 
			if(ans[j]<0) 
			{
				ans[j]-=res;
				break;
			}
		}
	}
	for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
	cout<<"\n";
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
