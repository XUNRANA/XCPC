#include <bits/stdc++.h>
using namespace std;
int n,m;
int sx,sy,sz,tx,ty,tz;
int x[1010],y[1010],z[1010];
int a[1010],b[1010],c[1010];
int sv,tv;

int vt[1010];
int d[1010];
vector<int>g[1010];
void solve()
{
    cin>>n>>m;
    cin>>x[0]>>y[0]>>z[0]>>x[n+1]>>y[n+1]>>z[n+1];
    for(int i=1;i<=n;i++) 
    {
        g[i].clear();
        cin>>x[i]>>y[i]>>z[i];
        if(x[0]==x[i]&&y[0]==y[i]&&z[0]-1==z[i]) sv=i;
        if(x[n+1]==x[i]&&y[n+1]==y[i]&&z[n+1]-1==z[i]) tv=i;
    }

    for(int i=1;i<=m;i++) cin>>a[i]>>b[i]>>c[i];
    map<array<int,2>,vector<array<int,2>>>mp;

    for(int i=1;i<=n;i++) mp[{x[i],y[i]}].push_back({z[i],i});

    for(auto &i:mp) 
    {
        sort(i.second.begin(),i.second.end());
        // cout<<"!"<<i.first[0]<<" "<<i.first[1]<<"\n";
        // for(auto j:i.second) cout<<j[0]<<" "<<j[1]<<"\n";
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            int nx=x[i]+a[j];
            int ny=y[i]+b[j];
            int nz=z[i]+1+c[j];
            if(mp.count({nx,ny}))
            {
                array<int,2> t={nz,1000000000};
                auto it=upper_bound(mp[{nx,ny}].begin(),mp[{nx,ny}].end(),t);



                if(it!=mp[{nx,ny}].begin())
                {
                    it--;
                    if((*it)[0]!=nz) 
                    {
                        // cout<<(*it)[0]<<" "<<nz<<" "<<c[j]<<"?!\n";
                        // cout<<i<<" "<<(*it)[1]<<"????\n";
                        g[i].push_back((*it)[1]);
                    }
                }
            }
        }
    }

    for(int i=1;i<=n;i++) d[i]=1e9,vt[i]=0;
    d[sv]=0;
    priority_queue<array<int,2>,vector<array<int,2>>,greater<array<int,2>> >q;
    q.push({d[sv],sv});
    while(!q.empty())
    {
        int u=q.top()[1];
        q.pop();
        if(vt[u]) continue;
        vt[u]=1;
        for(auto v:g[u])
        {
            if(d[v]>d[u]+1)
            {
                d[v]=d[u]+1;
                q.push({d[v],v});
            }
        }
    }
    // cout<<sv<<" "<<tv<<"!!!!!!!!!!!!!!!!!!!!!!!\n";
    if(d[tv]==1e9) cout<<"-1\n";
    else cout<<d[tv]<<"\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}
