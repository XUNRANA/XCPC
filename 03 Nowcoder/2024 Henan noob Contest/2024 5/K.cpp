#include <bits/stdc++.h>
using namespace std;
#define N 20010
int n,m,u[N],v[N],w[N],fa[N],s,t,l,r,mid;
int find(int x)
{
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
bool ck(int x)
{
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++) if(w[i]<=x) fa[find(u[i])]=find(v[i]);
	return find(s)==find(t);
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++) cin>>u[i]>>v[i]>>w[i];
	cin>>s>>t; 
	l=1,r=1e4;
	while(l<=r)
	{
		mid=l+r>>1;
		if(ck(mid)) r=mid-1;
		else l=mid+1;
	}
	cout<<l<<"\n";
} 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
