#include<bits/stdc++.h>
using namespace std;
#define int long long
int f(int a,int b,int s)
{
    if(s>20) return 1e18;
    if (!a||!b) return 1;
    int g=__gcd(a,b);
    return min(f(a-g,b,s+1),f(a,b-g,s+1))+1;
}
void solve()
{
    int a,b;
    cin>>a>>b;
    cout<<f(a,b,0)<<"\n";
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}