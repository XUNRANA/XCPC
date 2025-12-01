#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,n1,n2,s1,s2,u,v;
vector<int>g1[1010];
vector<int>g2[1010];
vector<pair<int,int>>g[1000010];
int d[1000010];
int vt[1000010];
void dij(int u)
{
    for(int i=1;i<=n*n;i++) d[i]=1e18,vt[i]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    d[u]=0;
    q.push({0,u});
    while(!q.empty())
    {
        int u=q.top().second;
        q.pop();
        if(vt[u]) continue;
        vt[u]=1;
        for(auto [v,w]:g[u])
        {
            if(d[v]>d[u]+w)
            {
                d[v]=d[u]+w;
                q.push({d[v],v});
            }
        }
    }
}
void solve()
{
    cin>>n>>s1>>s2;
    for(int i=1;i<=n;i++) g1[i].clear(),g2[i].clear();
    
    int f=0;
    set<pair<int,int>>st;
    vector<int>is(n+1,0);

    cin>>n1;
    for(int i=1;i<=n1;i++)
    {
        cin>>u>>v;
        if(u>v) swap(u,v);
        st.insert({u,v});
        g1[u].push_back(v);
        g1[v].push_back(u);
    }

    
    
    cin>>n2;
    for(int i=1;i<=n2;i++)
    {
        cin>>u>>v;
        if(u>v) swap(u,v);
        if(st.count({u,v})) 
        {
            f=1;
            is[u]=1;
            is[v]=1;
        }
        g2[u].push_back(v);
        g2[v].push_back(u);
    }

    if(!f)
    {
        cout<<"-1\n";
        return ;
    }

    for(int i=1;i<=n*n;i++) g[i].clear();

    for(int i=1;i<=n;i++) 
    for(int j=1;j<=n;j++)
    {
        int now=(i-1)*n+j;
        for(auto v1:g1[i])
        {
            for(auto v2:g2[j])
            {
                int nxt=(v1-1)*n+v2;
                g[now].push_back({nxt,abs(v1-v2)});
            }
        }
    }

   
    dij((s1-1)*n+s2);

    int res=1e18;
    for(int i=1;i<=n;i++)
    {
        if(is[i])
        {
            res=min(res,d[(i-1)*n+i]);
        }
    }
    if(res==1e18) res=-1;
    cout<<res<<"\n";
}
signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
