#include <bits/stdc++.h>
using namespace std;
vector<pair<int,string>>g[100010];
int n,m,l,a[100010];
string ans;
string dp[100010];
string f(string a,string b)
{
	string res;
	for(int i=0;i<l;i++) 
	if(a[i]==b[i]) res+='0';
	else res+='1';
	return res;
} 
void dfs(int u,int fa,string s)
{
	dp[u]=s;
	for(auto v1:g[u])
	{
		int v=v1.first;
		string s1=v1.second;
		if(v==fa) continue;
		dfs(v,u,f(s,s1));
	}
}

void solve()
{
	cin>>n>>m>>l;
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		string s;
		cin>>s;
		g[u].push_back({v,s});
		g[v].push_back({u,s});
	}
    
	for(int i=1;i<=m;i++) cin>>a[i];
	
    string t;
	for(int i=0;i<l;i++) t+='0';
	dfs(1,0,t);
	string ans=t;
	if(m&1)
	{
		ans=f(ans,dp[a[1]]);
		ans=f(ans,dp[a[m]]);
	}
	else
	{
		for(int i=2;i<=m-1;i++) ans=f(ans,dp[a[i]]);
	}
	cout<<ans<<"\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
//    cin>>T;
    while(T--) solve();
}
