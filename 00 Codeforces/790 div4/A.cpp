#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve() 
{

    string s;
    cin>>s;
    int s1=0;
    int s2=0;
    int c=0;
    for(auto i:s) 
    {
        s1+=i-'0';
        c++;
        if(c==3) s2=s1;
    }
    if(2*s2==s1) cout<<"YES\n";
    else cout<<"NO\n";
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