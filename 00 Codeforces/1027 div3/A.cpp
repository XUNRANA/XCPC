#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve () 
{
    int x;
    cin>>x;
    int nx=sqrt(x);
    if(nx*nx==x) cout<<"0 "<<nx<<"\n";
    else cout<<"-1\n";
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