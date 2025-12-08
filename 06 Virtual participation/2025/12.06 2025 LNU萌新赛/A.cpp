#include <bits/stdc++.h>
using namespace std;
int x,y,p1,p2;
void solve()
{
    for(int i=1;i<=4;i++) cin>>x>>y>>p1>>p2;
    if(y<x||(x==y&&p1<p2)) cout<<"A\n";
    else if(y>x||(x==y&&p1>p2)) cout<<"B\n";
    else cout<<"C\n";
}
signed main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}