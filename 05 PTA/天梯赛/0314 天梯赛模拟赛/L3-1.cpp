#include <bits/stdc++.h>
using namespace std;

vector<int>g[510];
int p[510];
int vt[510];
int f(int u)
{
	vt[u]=1;
	if(p[u]) return p[u];
	for(auto v:g[u]) p[u]+=f(v);
	return p[u];
}
void solve()
{
	int n,m,a,b,u,v;
	cin>>n>>m;
	while(m--)
	{
		cin>>u>>v;
		g[u].push_back(v);
	}
	cin>>a>>b;
	p[b]=1;//倒叙 
	int cnt=f(a);
	int fl=0;
	for(int i=1;i<=n;i++) 
	if(vt[i]&&!p[i])//访问了，但没有路径到b 
	{
		fl=1;
		break;
	}
	cout<<cnt<<" ";
	if(!fl) cout<<"Yes\n";
    else cout<<"No\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

