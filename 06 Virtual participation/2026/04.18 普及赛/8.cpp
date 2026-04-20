#include <bits/stdc++.h>
using namespace std;
#define int long long


void solve()
{
    int x;
    vector<int>a;
    while(cin>>x)
    {
        if(x==-1) break;
        a.push_back(x);
    }
    map<array<int,3>,int>mp;
    for(int i=0;i<a.size();i++)
    {
        if(i+2<a.size())
        {
            if(mp.count({a[i],a[i+1],a[i+2]}))
            {
                cout<<a[i]<<" "<<a[i+1]<<" "<<a[i+2]<<"\n";
                return ; 
            }
            mp[{a[i],a[i+1],a[i+2]}]++;
        }
    }
    cout<<"NONE\n";
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}