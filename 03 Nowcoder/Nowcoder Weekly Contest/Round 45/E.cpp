#include <bits/stdc++.h>
using namespace std;
#define int long long
int dep[100010],z,n;
vector<int>g[100010];
void dfs(int u,int fa)
{
	for(auto v:g[u])
	{
		if(v==fa) continue;
		dep[v]=dep[u]+1;
		dfs(v,u);
		if(dep[v]>dep[z]) z=v; 
	}
}

void solve()
{
	cin>>n;
	for(int i=1;i<n;i++) 
	{
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0);
	dep[z]=0;
	dfs(z,0);
	if(dep[z]>=5) cout<<"0\n";
    else if(dep[z]==4) cout<<"1\n";
    else if(dep[z]==3) cout<<"2\n";
    else cout<<n<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
