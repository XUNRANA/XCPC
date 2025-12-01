#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[1010][1010];
int b[1010];
int c1[1010];
int dp[1010][2];
int n;
//1 相等
//0 -1
//2 +1
bool ck(int idx,int f,int d)
{
    if(!f) 
    {
        for(int j=1;j<=n;j++) if(a[idx][j]==a[idx+1][j]+d) return 1;
    }
    else 
    {
        for(int j=1;j<=n;j++) if(a[j][idx]==a[j][idx+1]+d) return 1;
    }
    return 0;
}
void solve() 
{
    cin>>n;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin>>a[i][j];
    for(int i=1;i<=n;i++) cin>>b[i];
    for(int i=1;i<=n;i++) cin>>c1[i];
    dp[1][0]=0;//第一行不修改
    dp[1][1]=b[1];//第一行修改
    for(int i=1;i<n;i++)
    {
        dp[i+1][0]=dp[i+1][1]=1e18;
        if(!ck(i,0,0)) dp[i+1][0]=min(dp[i+1][0],dp[i][0]);
        if(!ck(i,0,-1)) dp[i+1][0]=min(dp[i+1][0],dp[i][1]);
        if(!ck(i,0,1)) dp[i+1][1]=min(dp[i+1][1],dp[i][0]+b[i+1]);
        if(!ck(i,0,0)) dp[i+1][1]=min(dp[i+1][1],dp[i][1]+b[i+1]);

    }
    int ans=min(dp[n][0],dp[n][1]);
    dp[1][0]=0;//第一列不修改
    dp[1][1]=c1[1];//第一列修改
    for(int i=1;i<n;i++)
    {
        dp[i+1][0]=dp[i+1][1]=1e18;
        if(!ck(i,1,0)) dp[i+1][0]=min(dp[i+1][0],dp[i][0]);
        if(!ck(i,1,-1)) dp[i+1][0]=min(dp[i+1][0],dp[i][1]);
        if(!ck(i,1,1)) dp[i+1][1]=min(dp[i+1][1],dp[i][0]+c1[i+1]);
        if(!ck(i,1,0)) dp[i+1][1]=min(dp[i+1][1],dp[i][1]+c1[i+1]);
    }
    ans+=min(dp[n][0],dp[n][1]);
    if(ans>=1e18) cout<<"-1\n";
    else cout<<ans<<"\n";
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