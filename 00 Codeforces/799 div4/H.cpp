#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() 
{
    int n,x;
    cin>>n;
    map<int,vector<int>>mp;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        mp[x].push_back(i);
    }
    int l=n,r=n;
    int ans=1;
    for(auto [y,v]:mp)
    {
        int s=v[0];
        int last=v[0];
        int res=1;
        for(int i=1;i<v.size();i++)
        {
            int num=v[i]-last-1;
            res=res-num+1;
            last=v[i];
            if(res<1) 
            {
                res=1;
                s=v[i];
            }
            if(res>ans)
            {
                ans=res;
                x=y;
                l=s;
                r=v[i];
            }
        }
    }
    cout<<x<<" "<<l<<" "<<r<<"\n";
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