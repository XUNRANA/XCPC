#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve() 
{
    int n,x;
    cin>>n;
    map<int,int>mp;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        mp[x]++;
    }
    int ans=0;
    for(auto i:mp) ans+=i.second-1;
    if(ans%2==0) cout<<n-ans<<"\n";
    else cout<<n-ans-1<<"\n";
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