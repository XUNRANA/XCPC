#include <bits/stdc++.h>
using namespace std;
#define int long long


void solve()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if(min(a,c)>=min(b,d)) cout<<"Gellyfish\n";
    else cout<<"Flower\n";
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