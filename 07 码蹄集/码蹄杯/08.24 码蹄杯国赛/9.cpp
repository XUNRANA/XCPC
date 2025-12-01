#include <bits/stdc++.h>
using namespace std;

#define int long long
#define inf 1e18

vector<int>g1[5];
int in[5];
int in1[5];
int a[5];
int k;


vector<array<int,2>>g[200010];
int d[200010][32];
// int vt[200010][32];
bool ck(int st,int j)
{
    for(int i=0;i<k;i++) in1[i]=in[i];
    
    for(int i=0;i<k;i++)
    {
        if(st>>i&1) 
        {
            for(auto v:g1[i])
            {
                in1[v]--;
            }
        }
    }
    return in1[j]==0;
}
int fx(int st)
{
    int res=0;
    for(int i=0;i<k;i++) if(st>>i&1) res++;
    return res;
}
void solve()
{
    int n,m,t;
    cin>>n>>m>>k>>t;
    for(int i=1;i<=n;i++) g[i].clear();
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    for(int i=0;i<k;i++) 
    {
        cin>>a[i];
        g1[i].clear();
        in[i]=0;
    }

    while(t--)
    {
        int u,v;
        cin>>u>>v;   

        for(int i=0;i<k;i++) 
        {
            if(a[i]==u) 
            {
                u=i;
                break;
            }
        }
        for(int i=0;i<k;i++) 
        {
            if(a[i]==v) 
            {
                v=i;
                break;
            }
        }

        in[v]++;
        g1[u].push_back(v);
    }

    for(int i=1;i<=n;i++) 
    for(int j=0;j<32;j++) 
    {
        d[i][j]=inf;
        // vt[i][j]=0;
    }

    priority_queue<array<int,4>,vector<array<int,4>>,greater<array<int,4>>>q;
    d[1][0]=0;
    q.push({d[1][0],0,1,0});
    
    while(!q.empty())
    {
        int u=q.top()[2];
        int st=q.top()[3];
        q.pop();
        // if(vt[u][st]) continue;
        // vt[u][st]=1;

        for(auto v:g[u])
        {
            int j;
            for(j=0;j<k;j++) if(a[j]==v[0]) break;

            
            if(j<k)//是关键点
            {
                if(st&j)//已经经过
                {
                    if(d[u][st]+v[1]<d[v[0]][st])
                    {
                        d[v[0]][st]=d[u][st]+v[1];
                        q.push({d[v[0]][st],fx(st),v[0],st});
                    }
                }
                else if(ck(st,j))
                {
                    if(d[u][st]+v[1]<d[v[0]][st+(1<<j)])
                    {
                        d[v[0]][st+(1<<j)]=d[u][st]+v[1];
                        q.push({d[v[0]][st+(1<<j)],fx(st+(1<<j)),v[0],st+(1<<j)});
                    }
                }
            }   
            else
            {
                if(d[u][st]+v[1]<d[v[0]][st])
                {
                    d[v[0]][st]=d[u][st]+v[1];
                    q.push({d[v[0]][st],fx(st),v[0],st});
                }
            }
        }
    }

    int ans=inf;
    for(int i=0;i<32;i++) ans=min(ans,d[n][i]);
    
    if(ans==inf) cout<<"impossible\n";
    else cout<<ans<<"\n";
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}
