#include <bits/stdc++.h>
using namespace std;



int a[200010];
vector<int>g[32];
int c[32][32];
void solve()
{
    int n,q;
    cin>>n>>q;
    for(int j=0;j<32;j++) g[j].clear();
    long long res=0;
    for(int i=1;i<=n;i++) 
    {
        cin>>a[i];
        res+=a[i];
        for(int j=0;j<32;j++) if(!(a[i]>>j&1)) g[j].push_back(a[i]);
    }
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
    }
    map<int,long long>mp;

    for(int j=0;j<32;j++)
    {
        for(int i=0;i<32;i++)
        {
            c[j][i]=0;
        }
    }
    for(int i=0;i<32;i++)
    {
        for(auto x:g[i])
        {
            for(int j=0;j<32;j++) if(x>>j&1) c[i][j]++; 
        }
    }

    for(int i=1;i<=q;i++)
    {
        int x;
        cin>>x;
        if(!x) cout<<res<<"\n";
        else
        {
            if(!mp.count(x)) 
            {
                long long ans=0;
                int i=__lg(x);
                for(int j=0;j<32;j++) 
                {
                    if(x>>j&1)
                    {
                        ans+=(g[i].size()-c[i][j]-c[i][j])*(1ll<<j);
                    }

                }
                mp[x]=ans;
            }
            cout<<res+mp[x]<<"\n";
        }
    }

}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}