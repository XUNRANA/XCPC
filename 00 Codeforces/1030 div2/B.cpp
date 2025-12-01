#include <bits/stdc++.h>
using namespace std;
#define int long long


void solve()
{
    int n;
    cin>>n;
    vector<array<int,3>>ans;
    ans.push_back({1,1,n});
    for(int i=2;i<=n;i++)
    {
        if(i-1!=1) 
        {
            ans.push_back({i,1,i-1});
            // cout<<i<<" "<<"1 "<<i-1<<"\n";
        }
        if(i!=n) 
        {
            ans.push_back({i,i,n});
            // cout<<i<<" "<<i<<" "<<n<<"\n";
        }
        // ans.push_back({i,1,n});
        // cout<<i<<" 1 "<<n<<"\n";
    }
    cout<<ans.size()<<"\n";
    for(auto i:ans) cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<"\n";

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