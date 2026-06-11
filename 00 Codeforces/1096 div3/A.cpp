#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int x,y;
    cin>>x>>y;
    if((x&1)&&(y&1)) cout<<"NO\n";
    else cout<<"YES\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}