#include <bits/stdc++.h>
using namespace std;
int u[5010],v[5010],f[5010];
int fa[510];
int n,m;
int find(int x)
{
	return x==fa[x]? x:fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
	int fx=find(x);
	int fy=find(y);
	fa[fx]=fy;
}
int fx()
{
	for(int i=0;i<n;i++) fa[i]=i;
	for(int i=1;i<=m;i++) if(f[i]) merge(u[i],v[i]);
	int ans=0;
	for(int i=0;i<n;i++) if(fa[i]==i) ans++;
	return ans;
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i];
		f[i]=1;
	} 
	int k;
	cin>>k;
	int fl=0;
	if(k==n) fl=1;
	int pre=fx();
	while(k--)
	{
		int x;
		cin>>x;
		for(int i=1;i<=m;i++) if(u[i]==x||v[i]==x) f[i]=0;
		int now=fx();
		if(now>=pre+2) cout<<"Red Alert: City "<<x<<" is lost!\n";
		else cout<<"City "<<x<<" is lost.\n";
		pre=now;
	}
	if(fl) cout<<"Game Over.\n";
}
int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

