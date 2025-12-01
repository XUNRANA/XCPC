#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int>g[500010];
int c[500010];
int w[500010];
int f[500010];
int l1[500010][2];
int l2[500010][2];
int n;
void init()
{
    for(int i=2;i<=5e5;i++)
    {
        if(!f[i])
        {
            for(int j=i;j<=5e5;j+=i)
            {
                g[j].push_back(i);
                f[j]=1;
            }
        }
    }
}
void solve() 
{
    init();
    int ans=1;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>w[i];
    for(int i=1;i<=n;i++) cin>>c[i];
    for(int i=1;i<=n;i++)
    {
        int mx=1;
        for(auto v:g[w[i]])//质因子
        {
            if(c[i]!=l1[v][1]) mx=max(mx,l1[v][0]+1);
            else mx=max(mx,l2[v][0]+1);
        }    
        for(auto v:g[w[i]])
        {
            vector<pair<int,int>>b;
            b.push_back({mx,c[i]});
            b.push_back({l1[v][0],l1[v][1]});
            b.push_back({l2[v][0],l2[v][1]});
            sort(b.begin(),b.end(),greater<pair<int,int>>());
            l1[v][0]=b[0].first;
            l1[v][1]=b[0].second;
            for(auto i:b)
            if(i.second!=l1[v][1])
            {
                l2[v][0]=i.first;
                l2[v][1]=i.second;
                break;
            }
        }
    }
    
    for(int i=1;i<=5e5;i++) ans=max(ans,l1[i][0]);
    cout<<ans<<"\n";
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}