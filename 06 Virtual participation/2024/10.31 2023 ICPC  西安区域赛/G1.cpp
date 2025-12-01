#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n;
    cin>>n;
    map<int,int>mp;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            while(n%i==0)
            {
                n/=i;
                mp[i]++;
            }
        }
    }
    if(n!=1) mp[n]++;
    int ans=1;
    for(auto i:mp) ans*=(2*i.second+1);
    ans=(ans+1)/2;
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
