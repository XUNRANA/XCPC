#include <bits/stdc++.h>
using namespace std;
#define N 200010
int n,m,c[N],d[N];
vector<int>g1[N],g2[N];
int mmax=0;
int dfs(int fn,int pn,int fm,int pm,int dep)
{
	// fn是当前遍历的第一棵树的结点，pn是fn的父结点
	// fm是当前遍历的第二棵树的结点，pm是fm的父结点
	mmax=max(mmax,dep);
	map<int,int>mp;
	for(auto t1:g1[fn])
	if(t1!=pn) mp[c[t1]]=t1;
	
	
	for(auto t2:g2[fm])
	{
		if(t2!=pm)
		{
			if(mp.count(d[t2])!=0)
			{
				mmax=max(mmax,dfs(mp[d[t2]],fn,t2,fm,dep+1));
			}
		}
	}
	return mmax;
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>c[i],g1[i].clear();
	for(int i=1;i<=m;i++) cin>>d[i],g2[i].clear();
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		g1[u].push_back(v);
		g1[v].push_back(u);
	}
	for(int i=1;i<m;i++)
	{
		int u,v;
		cin>>u>>v;
		g2[u].push_back(v);
		g2[v].push_back(u);
	}
	
	if(c[1]!=d[1]) cout<<"0\n";
	else
	{
		int res=dfs(1,0,1,0,1);
		cout<<res<<"\n";
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
