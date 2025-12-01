#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve() 
{
    string s;
    cin>>s;
    for(int i=1;i<s.size();i++) 
    if(s[i]!=s[0])
    {
        cout<<"0\n";
        return ;
    }
    cout<<s.size()-1<<"\n";
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}
