#include <bits/stdc++.h>
using namespace std;
#define int long long


void solve()
{
    int n,x,y;
    cin>>n>>y;
    int l=0,r=0;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        if(x==1) 
        {
            if(!l) l=i;
            else r=i;
        }
    }
    if((r-l+1)<=y) cout<<"YES\n";
    else cout<<"NO\n";
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