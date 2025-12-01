#include <bits/stdc++.h>
using namespace std;


void solve()
{
    char g;
    cin>>g;
    string a,b,c;
    cin>>a>>b;
    if(g=='F') c="NaiNai";
    else c="YeYe";
    cout<<a<<" "<<c<<" Nin Hao Ya ~";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}
