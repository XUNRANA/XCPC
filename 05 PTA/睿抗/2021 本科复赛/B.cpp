/*
#include <bits/stdc++.h>
using namespace std;
#define int long long
int dp[365*24*60+1];
int m[1010];
int c[1010];
void solve()
{
    int n,M;
    cin>>n>>M;
    for(int i=1;i<=n;i++) cin>>m[i];
    for(int i=1;i<=n;i++) cin>>c[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=M;j>=m[i];j--)
        dp[j]=max(dp[j-m[i]]+c[i],dp[j]);
    }
    cout<<dp[M]<<"\n";
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}
*/


#include <bits/stdc++.h>
using namespace std;
#define int long long
int dp[1000*30+1];//金币需要的最少时间
int m[1010];
int c[1010];
void solve()
{
    int n,M;
    cin>>n>>M;
    for(int i=1;i<=n;i++) cin>>m[i];
    for(int i=1;i<=n;i++) cin>>c[i];
    for(int i=1;i<=n*30;i++) dp[i]=1e9;
    for(int i=1;i<=n;i++)
    {
        for(int j=n*30;j>=c[i];j--)
        dp[j]=min(dp[j],dp[j-c[i]]+m[i]);
    }

    // for(int i=0;i<=n*30;i++) cout<<i<<" "<<dp[i]<<"\n";

    for(int i=n*30;i>=0;i--) 
    if(dp[i]<=M)
    {
        cout<<i<<"\n";
        return ;
    }
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}
