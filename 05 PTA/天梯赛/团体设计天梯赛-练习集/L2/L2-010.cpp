#include <bits/stdc++.h>
using namespace std;

int fa[110];
int a[110][110];
int n,m,q;
int find(int x)
{
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
void merge(int u,int v)
{
	fa[find(u)]=find(v);
}
void solve()
{
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++) fa[i]=i;
	
	for(int i=1;i<=m;i++)
	{
		int x,y,f;
		cin>>x>>y>>f;
		if(f==-1) a[x][y]=a[y][x]=-1;
		else merge(x,y);
	}
//	for(int i=1;i<=n;i++) cout<<i<<" "<<find(i)<<"\n";
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		if(a[x][y]!=-1&&find(x)==find(y)) cout<<"No problem\n";
		else if(a[x][y]!=-1&&find(x)!=find(y)) cout<<"OK\n";
		else if(a[x][y]==-1&&find(x)==find(y)) cout<<"OK but...\n";
		else if(a[x][y]==-1&&find(x)!=find(y)) cout<<"No way\n";
	}
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

