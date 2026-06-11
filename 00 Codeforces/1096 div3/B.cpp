#include <bits/stdc++.h>
using namespace std;
void solve()
{
    string s;
    int n;
    int c1=0,c2=0;
    cin>>n>>s;
    for(auto i:s) 
    if(i=='(') c1++;
    else c2++;
    
    if(c1==c2) cout<<"YES\n";
    else cout<<"NO\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}