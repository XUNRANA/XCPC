#include <bits/stdc++.h>
using namespace std;
#define int long long


void solve()
{
    int a,b;
    cin>>a>>b;
    if(a>=b) cout<<"Ba!\n"<<a-b<<"\n";
    else cout<<"Suan4 le ba.\n"<<b-a<<"\n";
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}

