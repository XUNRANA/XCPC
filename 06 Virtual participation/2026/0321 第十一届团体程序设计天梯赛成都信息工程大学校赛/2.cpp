#include <bits/stdc++.h>
using namespace std;
void solve()
{
    char ch;
    cin>>ch;
    if(isdigit(ch)) cout<<ch;
    else if(ch>='a'&&ch<='z') cout<<(10+(ch-'a'));
    else  cout<<(36+(ch-'A'));
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}