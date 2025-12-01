#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k;
string s;
int p[200010];
void solve() 
{
    cin>>n>>k;
    cin>>s;
    s=" "+s;
    int ans=0;
    for(int i=1;i<=n;i++) p[i]=p[i-1]+(s[i]=='B');
    for(int i=k;i<=n;i++)
    ans=max(ans,p[i]-p[i-k]);
    cout<<k-ans<<"\n";
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