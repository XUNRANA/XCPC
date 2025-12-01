#include <bits/stdc++.h>
using namespace std;
#define N 100010
#define int long long
int n,ans,mx,a[N],b[N],fa[N],f[N],sz[N];
int find(int x)
{
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}

void merge(int u,int v)
{
	int fu=find(u),fv=find(v);
	if(fu!=fv)
	{	
		fa[fu]=fv;
		sz[fv]+=sz[fu];
	}
}

void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	for(int i=1;i<=n;i++) fa[i]=i,sz[i]=0;
	for(int i=n;i>=2;i--)
	{
        int t=b[i];
		f[t]=1;
		sz[t]=a[t];
		if(f[t+1]) merge(t,t+1);
		if(f[t-1]) merge(t,t-1);
		mx=max(mx,sz[find(t)]);
		ans+=mx;
	}
	cout<<ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

