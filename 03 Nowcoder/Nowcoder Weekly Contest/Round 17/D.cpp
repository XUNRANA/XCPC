#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 100010
vector<tuple<int,int,int> >g[N];
int n,m,h,d[N],vt[N];
int ck(int x)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> >q;
    for(int i=1;i<=n;i++) d[i]=1e10,vt[i]=0;
    q.push({0,1});
    d[1]=0;
    while(!q.empty())
    {
        int u=q.top().second;
        q.pop();
        if(vt[u]) continue;
        vt[u]=1;
        for(auto [v,w,d1]:g[u])
        {
            if(w<x||vt[v]) continue;
            if(d[u]+d1<d[v])
            {
                d[v]=d[u]+d1;
                q.push({d[v],v});
            }
        }
    }
    if(d[n]<=h) return 1;
    return 0;
}
void solve()
{
	cin>>n>>m>>h;
	for(int i=1;i<=m;i++)
	{
        int u,v,w,d;
		cin>>u>>v>>w>>d;
		g[u].push_back({v,w,d});
		g[v].push_back({u,w,d});
	}
    int l=1,r=2e9;
    while(l<=r)
    {
        int mid=l+r>>1;
        if(ck(mid)) l=mid+1;
        else r=mid-1;
    }
    if(!ck(l-1)) cout<<"-1\n";
    else cout<<l-1<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

