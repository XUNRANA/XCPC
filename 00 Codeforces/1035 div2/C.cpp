#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n,l,r,k;
    cin>>n>>l>>r>>k;
    if(n==1) cout<<l<<"\n";
    else if(n==2) cout<<"-1\n";
    else 
    {
        //3 5 7 9
        if(n&1) cout<<l<<"\n";
        else 
        {
            if(__lg(l)==__lg(r)) cout<<"-1\n";
            else
            {
                if(k<=n-2) cout<<l<<"\n"; 
                else 
                {
                    int x=__lg(l);
                    x++;
                    cout<<(1ll<<x)<<"\n";
                }
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
    while(T--) solve();
}