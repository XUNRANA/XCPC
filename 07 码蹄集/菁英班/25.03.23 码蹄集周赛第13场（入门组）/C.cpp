#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int>g[100010];
int d[100010][2];
int vt[100010][2];
int fa[100010];
int find(int x)
{
    return x==fa[x]? x:fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
    fa[find(x)]=find(y);
}
bool ck(int x,int y)
{
    return (x!=1e18)&&(y!=1e18);
}
void solve()
{
    int n,m,u,v;
    cin>>n>>m;
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v;
        merge(u,v);
        g[u].push_back(v);
        g[v].push_back(u);
    }    
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    for(int i=1;i<=n;i++) d[i][0]=d[i][1]=1e18;
    for(int i=1;i<=n;i++) 
    if(find(i)==i)
    {
        d[i][1]=1;//1时刻开始
        q.push({1,i});
    }

    while(!q.empty())
    {
        int u=q.top().second;
        int t=q.top().first;
        q.pop();
        if(vt[u][t&1]) continue;
        vt[u][t&1]=1;
        for(auto v:g[u])
        {
            if(d[v][(t&1)^1]>t+1)
            {
                d[v][(t&1)^1]=t+1;
                q.push({d[v][(t&1)^1],v});
            }
        }
    }
    int nq;
    cin>>nq;
    while(nq--)
    {
        int u,v,x,y;
        cin>>u>>v>>x>>y;
        if(find(u)!=find(v)) cout<<"no\n";
        else
        {
            int x1=d[u][1];
            int x2=d[v][1];
            int x3=d[u][0];
            int x4=d[v][0];
            if(x==y)
            {
                if(ck(x1,x2)||ck(x3,x4))
                {
                    cout<<"yes\n";
                }
                else cout<<"no\n";
            }
            else
            {
                if(ck(x1,x4)||ck(x2,x3))
                {
                    cout<<"yes\n";
                }
                else cout<<"no\n";
            }
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
