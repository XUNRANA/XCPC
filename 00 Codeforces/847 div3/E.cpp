#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int x;
    cin>>x;
    int b=x/2;
    int a=b^x;
    if(a%2==b%2&&(a^b)==(a+b)/2)
    {
        cout<<a<<" "<<b<<"\n";
    }
    else cout<<"-1\n";
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