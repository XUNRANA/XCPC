#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve() 
{
    int n;
    int g=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        // cout<<abs(i-x)<<"\n";
        g=__gcd(g,abs(i-x));
    }
    int cnt=0;
    for(int i=1;i*i<=g;i++)
    {
        if(g%i==0) 
        {
            cnt++;
            if(g/i!=i) cnt++;
        }
    }
    cout<<cnt<<"\n";
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}