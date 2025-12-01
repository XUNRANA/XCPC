#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n,m,x,y;
    cin>>n>>m;
    int s1x=0,s1y=1;
    int s2x=0,s2y=1;
    map<pair<int,int>,int>mp;
    for(int i=1;i<=n;i++) 
    {
        mp[{s1x,s1y}]++;
        cin>>x>>y;
        int fz=s1x*y+x*s1y;
        int fm=s1y*y;
        int g=__gcd(fz,fm);
        fz/=g;
        fm/=g;
        s1x=fz;
        s1y=fm;
    }
    for(int i=1;i<=m;i++)
    {
        mp[{s2x,s2y}]++;
        cin>>x>>y;
        int fz=s2x*y+x*s2y;
        int fm=s2y*y;
        int g=__gcd(fz,fm);
        fz/=g;
        fm/=g;
        s2x=fz;
        s2y=fm;
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
	cin>>T;
	while(T--) solve();
}
