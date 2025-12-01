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
        int x;
        cin>>x;
        mp[x]++;
    } 

    //0 1 2 ... k-1 
    int ans=0;
    for(int i=0;i<k;i++)
    if(!mp.count(i)) ans++;

    if(!mp.count(k)) cout<<ans<<"\n";
    else 
    {
        ans=max(ans,mp[k]);
        cout<<ans<<"\n";
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