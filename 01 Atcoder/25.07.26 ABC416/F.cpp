#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int d[510][510];
int is[510];
void fx(int u)
{
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++) d[i][j]=min(d[i][j],d[i][u]+d[u][j]);
}
void solve()
{

    cin>>n>>m;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++) if(i!=j) d[i][j]=1e18;

    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        d[u][v]=min(d[u][v],w);
        d[v][u]=min(d[v][u],w);
    }
    for(int i=1;i<=n;i++) floyd(i);
    
    int k,t;
    cin>>k>>t;
    vector<int>tt;
    for(int i=1;i<=k;i++) 
    {
        int x;
        cin>>x;
        for(auto j:tt) 
        {
            d[x][j]=min(d[x][j],t);
            d[j][x]=min(d[j][x],t);
        }
        tt.push_back(x);
    }
    int q;
    cin>>q;
    while(q--)
    {
        int op;
        cin>>op;
        if(op==1)
        {
            int u,v,w;
            cin>>u>>v>>w;
            d[u][v]=min(d[u][v],w);
            d[v][u]=min(d[v][u],w);
        }
        else if(op==2)
        {
            int x;
            cin>>x;
            for(auto j:tt) 
            {
                d[x][j]=min(d[x][j],t);
                d[j][x]=min(d[j][x],t);
            }
            tt.push_back(x);
        }
        else if(op==3)
        {
            int s=0;
            for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            if(d[i][j]!=1e18) s+=d[i][j];
            cout<<s<<"\n";
        }
    }
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}

