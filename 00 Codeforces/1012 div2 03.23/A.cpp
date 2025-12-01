#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int x,y,a;
    cin>>x>>y>>a;
    a++;
    if(a%(x+y)==0) cout<<"YES\n";
    else
    {
        a%=(x+y);
        if(a<=x) cout<<"NO\n";
        else cout<<"YES\n";
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}
