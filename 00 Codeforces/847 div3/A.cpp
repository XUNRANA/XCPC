#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    string s="314159265358979323846264338327";
    string t;
    cin>>t;
    for(int i=t.size();i>=1;i--)
    {
        if(s.substr(0,i)==t.substr(0,i))
        {
            cout<<i<<"\n";
            return ;
        }
    }
    cout<<"0\n";
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