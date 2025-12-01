#include <bits/stdc++.h>
using namespace std;
#define int long long
set<int>st[200010];
void solve()
{
    int n;
    string s;
    cin>>n;
    cin>>s;
    s=" "+s;
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        st[u].insert(v);
        st[v].insert(u);
    }
    queue<int>q;
    int ans=0;
    for(int i=1;i<=n;i++) 
    if(st[i].size()==1) 
    {
        q.push(i);
        ans++;
    }
    while(!q.empty())
    {
        auto u=q.front();
        q.pop();
        for(auto v:st[u])
        {
            if(s[v]==s[u])
            {
                st[v].erase(u);
                if(st[v].size()==1) 
                {
                    q.push(v);
                    ans++;
                }
            }
        }
    }
    cout<<n-ans<<"\n";
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