#include <bits/stdc++.h>
using namespace std;
#define int long long
bool ck(int x)
{
    int h=x/60;
    int m=x%60;
    if(h%10*10+h/10==m) return 1;
    return 0;
}
void solve() 
{
    int h,m,x;
    string s;
    cin>>s>>x;
    h=stoi(s.substr(0,2));
    m=stoi(s.substr(3,2));
    int now=h*60+m;
    int p=now;
    int ans=0;
    while(1)
    {
        now+=x;
        now%=24*60;
        if(ck(now)) ans++;
        if(now==p) break;
    }
    cout<<ans<<"\n";
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