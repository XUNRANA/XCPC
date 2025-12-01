#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;
    cin>>n;
    if(n&1)
    {
        cout<<(n+1)/2<<"\n";
        for(int i=1;i<=(n+1)/2;i++) cout<<i<<" ";
        cout<<"\n";
    }
    else
    {
        if(n<=4) 
        {
            cout<<"-1\n";
            return ;
        }
        cout<<(n+1)/2<<"\n";
        for(int i=1;i<=(n+1)/2;i++) 
        {
            if(i==(n+1)/2) cout<<i+1<<" ";
            else cout<<i<<" ";
        }
        cout<<"\n";
    }
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
