#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int h,h1,h2;
    cin>>h>>h1>>h2;
    string ans="";
    if(h<h1) ans="Bu Kan";
    else if(h<h2) ans="Zhe Gua Bao Shu Ma";
    else ans="Chi Gua";
    cout<<h<<"\n";
    cout<<ans<<"\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}