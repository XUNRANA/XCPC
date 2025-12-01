#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<int>g[200010];
int w[200010];
void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) g[i].push_back(0);
    for(int i=1;i<=n;i++)
    {
        int c;
        cin>>c;
        g[c].push_back(i);
    }
    for(int i=1;i<=n;i++) g[i].push_back(n+1);
    for(int i=1;i<=n;i++) cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        int res=w[i];
        vector<array<int,2>>b;
        for(int j=1;j<g[i].size();j++)
        {
            if(g[i][j-1]==g[i][j]-1) continue;
            b.push_back({g[i][j-1]+1,g[i][j]-1});
        }
        // cout<<i<<"\n";
        int last=-1;
        for(auto j:b) 
        {
            if(last!=-1)
            {
                res+=min(w[i],j[0]-1-last+1);
            }
            res+=j[1]-j[0]+1;
            last=j[1]+1;
            // cout<<j[0]<<" "<<j[1]<<"\n";
        }
        cout<<res<<" ";
    }
    cout<<"\n";
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