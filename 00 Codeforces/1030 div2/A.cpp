#include <bits/stdc++.h>
using namespace std;
#define int long long


void solve()
{
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        if(i<k) cout<<"1";
        else cout<<"0";
    }
    cout<<"\n";
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