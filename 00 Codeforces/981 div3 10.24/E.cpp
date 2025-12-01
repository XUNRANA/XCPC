#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,p[1000010],fa[1000010];
int find(int x)
{
	return x==fa[x]? x:fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
	fa[find(x)]=find(y);
}
int sz[1000010];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>p[i],sz[i]=0,fa[i]=i;
	for(int i=1;i<=n;i++) merge(i,p[i]);
	for(int i=1;i<=n;i++) sz[find(i)]++;
//	for(int i=1;i<=n;i++) cout<<i<<" "<<sz[i]<<"\n";
	int ans=0;
	for(int i=1;i<=n;i++) 
	if(sz[i]==3) ans++;
	else if(sz[i]>3) ans+=(sz[i]+1)/2-1;
	
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
