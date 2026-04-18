#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<array<int,2>>g[10010];

void fx(int x)
{
    vector<int>ans;
    ans.push_back(x);
    set<int>st;
    st.insert(x);
    while(g[x].size())
    {
        int f=0;
        for(auto j:g[x])
        {
            if(st.count(j[1])) continue;

            x=j[1];
            ans.push_back(x);
            st.insert(x);
            f=1;
            break;
        }
        if(!f) break;

    }

    if(ans.size()==1) cout<<ans[0]<<"\n";
    else 
    {
        int f=0;
        for(auto i:ans) 
        {
            if(f) cout<<"->";
            cout<<i;
            f=1;
        }
        cout<<"\n";
    }

}
void solve()
{
    
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({-w,v});
    }
    for(int i=1;i<=n;i++) 
    {
        sort(g[i].begin(),g[i].end());
        // cout<<i<<"\n";
        // for(auto j:g[i]) cout<<j[0]<<" "<<j[1]<<"!\n";
    }
    int k;
    cin>>k;
    for(int i=1;i<=k;i++) 
    {
        int x;
        cin>>x;
        fx(x);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}