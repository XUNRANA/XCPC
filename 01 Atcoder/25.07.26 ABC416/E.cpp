#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int d[510][510];
void fx(int u)
{
    for(int i=0;i<=n;i++)
    for(int j=0;j<=n;j++) d[i][j]=min(d[i][j],d[i][u]+d[u][j]);
}
void print()
{
    for(int i=1;i<=n;i++,cout<<"\n")
    for(int j=1;j<=n;j++) cout<<d[i][j]<<" ";

    cout<<"\n";
}
void solve()
{

    cin>>n>>m;
    for(int i=0;i<=n;i++)
    for(int j=0;j<=n;j++) if(i!=j) d[i][j]=1e18;

    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        d[u][v]=min(d[u][v],w);
        d[v][u]=min(d[v][u],w);
    }

    int k,t;
    cin>>k>>t;
    for(int i=1;i<=k;i++) 
    {
        int x;
        cin>>x;
        d[x][0]=min(d[x][0],t);
        d[0][x]=min(d[0][x],0ll);
    }

    for(int i=0;i<=n;i++) fx(i);

    // print();
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
            fx(u);
            fx(v);
        }
        else if(op==2)
        {
            int x;
            cin>>x;
            d[x][0]=min(d[x][0],t);
            d[0][x]=min(d[0][x],0ll);
            fx(0);
            fx(x);
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

