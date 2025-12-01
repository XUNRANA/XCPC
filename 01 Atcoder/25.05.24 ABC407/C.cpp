#include <bits/stdc++.h>
using namespace std;
#define int long long


void solve()
{
    
    string s;
    cin>>s;
    reverse(s.begin(),s.end());
    char p='0';
    int ans=s.size();
    for(auto i:s) 
    {
        ans+=((i-p)+10)%10;
        // cout<<((i-p)+10)%10<<"\n";
        p=i;
    }
    cout<<ans<<"\n";

}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}