#include <bits/stdc++.h>
using namespace std;
#define int long long




void solve()
{
    int x,y;
    cin>>x>>y;
    for(int i=x+1;i<y;i++)
    {           
        if(__gcd(i,x)==1&&__gcd(i,y)==1)
        {
            cout<<i<<"\n";
            return ;
        }
    }
    cout<<"-1\n";
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