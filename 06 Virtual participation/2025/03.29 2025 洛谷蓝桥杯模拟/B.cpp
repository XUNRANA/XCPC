#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 998244353

void solve() 
{
    set<int>st;
    for(int i=1;i<=20;i++)
    {
        int x=pow(2,i);
        int y=pow(5,i);
        while(x>=10)
        {
            x/=10;
        }
        while(y>=10)
        {
            y/=10;
        }
        // cout<<x<<" "<<y<<" "<<x*y<<"\n";
        st.insert(x*y);
    }
    int ans=0;
    for(auto i:st) ans+=i;
    cout<<ans<<"\n";
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}