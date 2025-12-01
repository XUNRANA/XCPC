#include <bits/stdc++.h>
using namespace std;
#define N 100010
#define int long long
int n,m,u,v,w,ans,ans1,a[N],vt[N];
vector<pair<int,int>>g[N];
int get(int a,int b)
{
    int c2=0,c5=0;
    while(a%2==0) a/=2,c2++;
    while(a%5==0) a/=5,c5++;
    while(b%2==0) b/=2,c2++;
    while(b%5==0) b/=5,c5++;
    return min(c2,c5);
}
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v;
        w=get(a[u],a[v]);
        ans+=w;
        g[u].push_back({w,v});
        g[v].push_back({w,u});
    }
    
    priority_queue< pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> >q;
    q.push({0,1});
    while(!q.empty())
    {
        int w=q.top().first;
        int u=q.top().second;
        q.pop();
        if(vt[u]) continue;
        vt[u]=1;
        ans1+=w;
        for(auto v:g[u]) 
        {
            if(vt[v.second]) continue;
            q.push(v);
        }
    }
    cout<<ans-ans1<<"\n";
}


signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
