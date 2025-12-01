#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[210][210];
void solve() 
{
    int n,m,x;
    cin>>n>>m;
    map<int,int>mp[2];
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
    {
        cin>>x;
        a[i][j]=x;
        mp[0][i-j]+=x;
        mp[1][i+j]+=x;
    }
    int ans=0;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
    {
        ans=max(ans,mp[1][i+j]+mp[0][i-j]-a[i][j]);
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