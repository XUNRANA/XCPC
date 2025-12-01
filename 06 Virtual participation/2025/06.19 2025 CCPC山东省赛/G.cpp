#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n,k;
    cin>>n>>k;
    map<int,int>mp;
    for(int i=1;i<=n;i++)
    {
        int w,t;
        cin>>w>>t;
        w-=t;
        mp[w]++;
    }

    int s=0;
    int res=1e18;
    for(auto [x,y]:mp) 
    {
        s+=y;
        res=min(res,x-s+1);
    }
    cout<<k-res<<"\n";
} 

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}

