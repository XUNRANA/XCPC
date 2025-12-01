#include <bits/stdc++.h>
using namespace std;
#define int long long

int f(int x)
{
    string s="";
    for(int i=30;i>=0;i--)
    {
        if(x>>i&1)
        {
            s+='1';
        }
        else 
        {
            if(s!="") s+='0';
        }
    }
    int ans=0;
    int v=1;
    for(auto i:s) 
    {
        ans+=(i-'0')*v;
        v*=2;
    }
    return ans;
}
int n,m,c[1010];
int dp[1010][1010][2];
void solve()
{
    cin>>n>>m;
    int ans=0;
    for(int i=1;i<=n;i++) 
    {
        cin>>c[i];
        ans+=c[i];
        c[i]=f(c[i])-c[i];
    }    

    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) dp[i][j][0]=dp[i][j][1]=-1e18;
    
    dp[1][1][1]=c[1];
    dp[1][0][0]=0;

    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(j>=1) 
            {
                dp[i][j][1]=max(dp[i][j][1],dp[i-1][j][1]+c[i]);
                dp[i][j][1]=max(dp[i][j][1],dp[i-1][j-1][0]+c[i]);
            }
            dp[i][j][0]=max(dp[i-1][j][0],dp[i-1][j][1]);
        }
    }
    
    int res=0;
    for(int j=0;j<=m;j++) 
    {
        res=max(res,dp[n][j][0]);
        if(j>=1) res=max(res,dp[n][j][1]);
    }
    cout<<res+ans<<"\n";
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