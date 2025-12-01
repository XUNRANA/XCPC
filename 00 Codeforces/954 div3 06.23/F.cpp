#include <bits/stdc++.h>
using namespace std;
#define N 100010
#define int long long
vector<int>g[N];

int dfn[N],low[N],tot,cut[N],root;
void tarjan(int x)
{
	//入x时，盖戳，入栈 
	dfn[x]=low[x]=++tot;
	int child=0; 
	for(auto y:g[x])
	{
		if(!dfn[y])//若y尚未访问 
		{
			tarjan(y);
			low[x]=min(low[x],low[y]);//回x时更新low 
			if(low[y]>=dfn[x])//判割点 
			{
				child++;
				if(x!=root||child>1) cut[x]=1;//根结点两棵子树 
			}
		}
		else  //y已访问 
		low[x]=min(low[x],dfn[y]);//更新low 
	}
}

void solve()
{
	int n,m,ans;
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
	{
		g[i].clear();
		dfn[i]=low[i]=cut[i]=0;
		root=tot=0;
	}
	vector<pair<int,int>>vt;
	for(int i=1;i<=m;i++)
	{
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
		vt.push_back({u,v});
	}
	for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i);
	ans=n*(n-1)/2;
	for(int i=1;i<=n;i++) if(cut[i]) cout<<i<<" ";
	cout<<"\n";
	
	cout<<ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
