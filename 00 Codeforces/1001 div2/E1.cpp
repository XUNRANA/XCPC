#include <bits/stdc++.h>
using namespace std;

#define N 400010
vector<int>g[N];
int L[N],R[N],val[N],mxp[N],mxs[N];
int dfn;
vector<int>b;
void dfs(int u,int fa)
{
    L[u]=++dfn;
	b.push_back(val[u]);
    for(auto v:g[u])
    {
        if(v==fa) continue;
        dfs(v,u);
    }
    R[u]=dfn;
}
void solve()
{
	int n;
    cin>>n;
	vector<pair<int,int>>path;
    for(int i=1;i<=n;i++) 
	{
		cin>>val[i];
		path.push_back({val[i],i});
		g[i].clear();
	}
    for(int i=1;i<n;i++)
    {
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
    }

	dfn=0;
	b.clear();
	b.push_back(0);
    dfs(1,0);
    
	for(int i=1;i<=n;i++) mxp[i]=max(mxp[i-1],b[i]);
	mxs[n+1]=0;
	for(int i=n;i>=1;i--) mxs[i]=max(mxs[i+1],b[i]);

	sort(path.begin(),path.end(),greater<pair<int,int>>());
    for(int j=0;j<path.size();j++)
    {
		int i=path[j].second;
		int l=L[i];
		int r=R[i];
		if(max(mxp[l-1],mxs[r+1])>val[i]) 
		{
			cout<<i<<"\n";
			return ;
		}
    }
	cout<<"0\n";
}

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
