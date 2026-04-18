#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n,x,y;
    string s,ans;
    int mx=-1;
    int cnt=0;
    cin>>n>>x;
    while(n--)
    {
        cin>>s>>y;
        if(y>=x) cnt++;

        if(y>mx)
        {
            mx=y;
            ans=s;
        }
    }
    cout<<cnt<<"\n";
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