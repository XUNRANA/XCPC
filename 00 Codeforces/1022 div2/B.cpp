#include <bits/stdc++.h>
using namespace std;

void solve () 
{
    int n,x;
    cin>>n>>x;
    if(x==0)
    {
        if(n==1) cout<<"-1\n";
        else if(n&1) cout<<n+3<<"\n";
        else cout<<n<<"\n";
    }
    else if(__builtin_popcount(x)>=n) cout<<x<<"\n";
    else
    {
        if(__builtin_popcount(x)>=2)
        {
            int t=n-__builtin_popcount(x);
            if(t&1)
            {
                cout<<x+t+1<<"\n";
            }
            else cout<<x+t<<"\n";
        }
        else
        {
            if(x==1)
            {
                if(n&1) cout<<n<<"\n";
                else cout<<n+3<<"\n";
            }
            else
            {
                int t=n-__builtin_popcount(x);
                cout<<x+(t+1)/2*2<<"\n";
            }
        }
    }
}


signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--)
    solve();
}