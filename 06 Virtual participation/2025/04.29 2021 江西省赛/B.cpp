#include <bits/stdc++.h>
using namespace std;
#define int long long



void solve() 
{
    int x,y;
    cin>>x>>y;
    vector<int>ans;
    ans.push_back(0);
    swap(x,y);
    while(y)
    {
        ans.push_back(x/y);
        x%=y;
        swap(x,y);
    }
    cout<<ans.size()-1<<" ";
    for(auto i:ans) cout<<i<<" ";
    cout<<"\n";
}

signed  main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}
