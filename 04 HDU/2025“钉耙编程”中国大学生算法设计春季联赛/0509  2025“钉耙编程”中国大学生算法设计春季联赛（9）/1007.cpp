#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
int idx[100010];
void solve() 
{
    cin>>n;
    for(int i=1;i<=n;i++) 
    {
        int x;
        cin>>x;
        idx[x]=i;
    }
    int cnt=1;
    int ans=1;
    for(int i=1;i<=n;i++) 
    if(i+1<=n&&idx[i]<idx[i+1])
    {
        cnt++;
    }
    else
    {
        ans=max(ans,cnt);
        cnt=1;
    }
    ans=max(ans,cnt);
    cout<<n-ans<<"\n";
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