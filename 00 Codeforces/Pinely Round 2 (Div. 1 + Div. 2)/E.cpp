
#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int>g[200010];
int in[200010];
int h[200010];
void solve()
{
    int n,m,k,a,b;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) cin>>h[i],g[i].clear(),in[i]=0;
    for(int i=1;i<=m;i++)
    {
        cin>>a>>b;
        g[a].push_back(b);
        in[b]++;
    }
    vector<pair<int,int>>vt;
    for(int i=1;i<=n;i++) if(!in[i]) vt.push_back({h[i],i});
    sort(vt.begin(),vt.end());
    vector<int>res(n+1,0);
    queue<int>q;
    for(auto i:vt) 
    {
        res[i.second]=h[i.second];
        q.push(i.second);
    }
    
    
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(auto v:g[u])
        {
            if(h[v]>=h[u]) res[v]=max(res[v],res[u]+h[v]-h[u]);
            else res[v]=max(res[v],res[u]+h[v]-h[u]+k);
            in[v]--;
            if(!in[v]) q.push(v);
        }
    }
 
    int mi=1e18;
    int mx=0;
    for(int i=1;i<=n;i++) 
    {
 
        mx=max(mx,res[i]);
        mi=min(mi,res[i]);
    }
    int ans=mx-mi;
    for(int i=0;i<vt.size()-1;i++)
    {
        int u=vt[i].second;
        mi=vt[i+1].first;
        res[u]+=k;
        mx=max(mx,res[u]);
        q.push(u);
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            for(auto v:g[u])
            {
                int t=res[u]+h[v]-h[u];
                if(h[v]<h[u]) t+=k;
                if(t>res[v])
                {
                    res[v]=t;
                    mx=max(mx,t);
                    q.push(v);
                }
            }
        }
        ans=min(ans,mx-mi);
    }
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