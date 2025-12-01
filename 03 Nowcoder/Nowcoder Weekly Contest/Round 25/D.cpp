#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 200010
int n,sz[N],res;
vector<int>g[N];
string s;
void dfs(int u,int fa)
{
    sz[u]=1;
    for(auto v:g[u])
    {
        if(v==fa) continue;
        dfs(v,u);
        sz[u]+=sz[v];
        if(s[v]==s[u]) sz[u]--;
    }
}
void dfs1(int u,int fa)
{
    for(auto v:g[u])
    {
        if(v==fa) continue;
        dfs1(v,u);
        int t=sz[1]-sz[v];
        if(s[v]==s[u]) t++;
        res+=abs(t-sz[v]);
    }
}
void solve()
{
    cin>>n>>s;
    s=" "+s;
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    dfs1(1,0);
    cout<<res<<"\n";
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    //cin>>T;
    while(T--) solve();
}


/*
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 200010
int n,sz[N],res;
vector<int>g[N];
string s;
void dfs(int u,int fa)
{
	sz[u]=1;
	for(auto v:g[u])
	{
		if(v==fa) continue;
		dfs(v,u);
		if(s[v]!=s[u]) sz[u]+=sz[v];
		else sz[u]+=sz[v]-1;
	}
}
void dfs1(int u,int fa)
{
	for(auto v:g[u])
	{
		if(v==fa) continue;
		int sv=sz[v];
		if(s[u]==s[v]) sz[u]-=sv-1;
		else sz[u]-=sv;
		
	//	cout<<u<<" "<<v<<" "<<sz[u]<<" "<<sz[v]<<"\n";
		res+=abs(sz[u]-sz[v]);
		
		int su=sz[u];
		if(s[u]==s[v]) sz[v]+=su-1;
		else sz[v]+=su;
		
//		cout<<v<<"\n";
//		for(int i=1;i<=n;i++) cout<<sz[i]<<" ";
//		cout<<"\n";
		dfs1(v,u);
	
		if(s[u]==s[v]) sz[u]+=sv-1;
		else sz[u]+=sv;
		
		if(s[u]==s[v]) sz[v]-=su-1;
		else sz[v]-=su;
	}
}
void solve()
{
	cin>>n>>s;
	s=" "+s;
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0);
	dfs1(1,0);
	cout<<res<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
*/

