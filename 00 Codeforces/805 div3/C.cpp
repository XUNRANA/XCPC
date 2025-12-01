#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve() 
{
    int n,q;
    cin>>n>>q;
    map<int,vector<int>>mp;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        mp[x].push_back(i);
    }
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        if(!mp.count(x)||!mp.count(y)) cout<<"NO\n";
        else if(mp[x][0]<mp[y].back()) cout<<"YES\n";
        else cout<<"NO\n";
    }
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}