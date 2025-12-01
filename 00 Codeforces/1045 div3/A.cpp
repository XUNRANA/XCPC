#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;
    cin>>n;
    int c0=0,c1=0,c2=0;
    while(n--)
    {
        int x;
        cin>>x;
        if(x==0) c0++;
        else if(x==1) c1++;
        else c2++;
    }

    if(c2&1) cout<<c0+2<<"\n";
    else cout<<c0<<"\n";
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}