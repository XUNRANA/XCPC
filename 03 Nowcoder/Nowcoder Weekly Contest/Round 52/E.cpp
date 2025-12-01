#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 100010
int n,m,u,v,a[N],fa[N],res;
int find(int x)
{
    if(fa[x]==x) return x;
    return fa[x]=find(fa[x]);
}
void solve()
{
	cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i],fa[i]=i;
    while(m--)
    {
        cin>>u>>v;
        fa[find(u)]=find(v);
    }
    for(int i=1;i<=n;i++) a[find(i)]=max(a[find(i)],a[i]);

    int mi=1e9;
    map<int,int>mp;
    for(int i=1;i<=n;i++) if(fa[i]==i) mp[i]=a[i],mi=min(mi,a[i]);

    
    for(auto i:mp) res+=i.second;
    cout<<res-mi;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
