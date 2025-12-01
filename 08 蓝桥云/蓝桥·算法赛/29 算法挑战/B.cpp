#include <bits/stdc++.h>
using namespace std;
int n,s,e,d;
int fx(int x)
{
    if(x<=e) return e-x;
    else return e+n-x;
}
void solve()
{
    cin>>n>>s>>e>>d;
    d%=n;
    s--;
    e--;
    cout<<min({fx((s+d)%n),fx((s-d+n)%n),fx(s)});
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}