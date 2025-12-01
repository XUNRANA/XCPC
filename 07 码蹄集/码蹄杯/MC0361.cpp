#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 998244353
int n,k;
int a[1000010];
int dp[1000010];
int p[1000010];
void solve()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i],dp[i]=1e18;
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++) p[i]=p[i-1]+a[i];
    k=min(k,3ll);//4 =2+2   5=2+3  6=3+3
    for(int i=1;i<=n;i++)
    {
        //至少两个
        //...i-k..i-2 i-1 i 
        for(int j=2;j<=k&&i-j>=0;j++)
        {
            dp[i]=min(dp[i],dp[i-j]+j*a[i]-(p[i]-p[i-j]));
            //dp[i-j]+j*a[i]-(p[i]-p[i-j])
            // dp[i-j]+p[i-j]+j*a[i]-p[i]
        }
    }
    cout<<dp[n]<<"\n";
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}
