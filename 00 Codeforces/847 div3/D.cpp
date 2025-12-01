#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;
    cin>>n;
    map<int,int>mp;
    while(n--)
    {
        int x;
        cin>>x;
        mp[x]++;
    }
    // 1 2 2 3 3 4
    int lx=-1,ly=-1;
    int ans=0;
    for(auto [x,y]:mp)
    {
        if(lx+1!=x) ans+=y;
        else ans+=max(y-ly,0ll);
        lx=x;
        ly=y;
    }
    cout<<ans<<"\n";
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