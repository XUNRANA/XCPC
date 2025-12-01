#include <bits/stdc++.h>
using namespace std;
#define int long long
int query(int l,int r)
{
    return (l+r)*(r-l+1)/2;
}
int lcm(int x,int y)
{
    return x/__gcd(x,y)*y;
}
void solve()
{
    int n,x,y;
    cin>>n>>x>>y;
    int cx=n/x;
    int cy=n/y;
    int l=lcm(x,y);
    int c=n/l;
    cx-=c;
    cy-=c;
    int ans=query(n-cx+1,n)-query(1,cy);
    cout<<ans<<"\n";
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