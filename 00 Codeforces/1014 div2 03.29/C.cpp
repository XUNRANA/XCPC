#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n;
    cin>>n;
    vector<int>o,e;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        if(x%2==0) e.push_back(x);
        else o.push_back(x);
    }
    sort(o.begin(),o.end());
    sort(e.begin(),e.end());
    if(o.empty()||e.empty())
    {
        if(o.empty()) cout<<e[e.size()-1]<<"\n";
        else cout<<o[o.size()-1]<<"\n";
    }
    else
    {
        int s=0;
        for(auto i:o) s+=i;
        for(auto i:e) s+=i;
        cout<<s-(o.size()-1)<<"\n";
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}
