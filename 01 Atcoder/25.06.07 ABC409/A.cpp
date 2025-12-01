#include <bits/stdc++.h>
using namespace std;
#define int long long


void solve()
{
    int n;
    string s,t;
    cin>>n>>s>>t;
    for(int i=0;i<n;i++)
    {
        if(s[i]==t[i])
        {
            if(s[i]=='o')
            {
                cout<<"Yes\n";
                return ;
            }
        }
    }
    cout<<"No\n";
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