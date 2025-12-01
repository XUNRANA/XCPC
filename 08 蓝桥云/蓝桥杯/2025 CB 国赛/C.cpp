#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;
    cin>>n;
    map<pair<int,int>,int>mp;
    for(int i=1;i<=n;i++)
    {
        int x,y,xx,yy;
        cin>>x>>y>>xx>>yy;
        int dx=xx-x;
        int dy=yy-y;
        int g=__gcd(abs(dx),abs(dy));
        dx/=g;
        dy/=g;
        for(int i=x,j=y;;i+=dx,j+=dy)
        {
            mp[{i,j}]++;
            if(i==xx&&j==yy) break;
        }
    }
    int ans=0;
    for(auto i:mp) if(i.second>=2) ans++;
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