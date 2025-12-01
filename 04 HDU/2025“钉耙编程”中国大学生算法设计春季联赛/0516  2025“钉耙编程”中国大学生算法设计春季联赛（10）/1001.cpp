#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() 
{
    int n;
    cin>>n;
    while(n--)
    {
        string s;
        int t;
        cin>>s>>t;
        int now=stoll(s.substr(0,2))*60+stoll(s.substr(3,2));
        now+=t*60;
        now=(now+24*60)%(24*60);
        printf("%02d:%02d\n",now/60,now%60);
    }
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