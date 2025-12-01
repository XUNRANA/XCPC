#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 1000000007

int gc[5010][5010];
void init()
{
    for(int i=0;i<=5000;i++)
    {
        for(int j=0;j<=5000;j++) 
        {
            gc[i][j]=__gcd(i,j);
        }
    }
    // cout<<gc[12][8]<<"\n";
}
void solve()
{
    int n,m;
    cin>>n>>m;
    vector<vector<vector<int>>>dp(2,vector<vector<int>>(m+2,vector<int>(n+1,0)));
    // 前i个数，选了j个数，gcd为k的方案数有多少

    dp[0][0][0]=1;
    int f=0;
    for(int i=1;i<=n;i++)//前i个数
    {
        for(int k=0;k<=m;k++)
        for(int g=0;g<=i;g++) dp[f^1][k][g]=0;

        //前i-1个数--->前i个数
        for(int k=0;k<=m;k++)
        {
            for(int g=0;g<=i-1;g++)
            {
                dp[f^1][k][g]+=dp[f][k][g];
                dp[f^1][k][g]%=P;
                dp[f^1][k+1][gc[g][i]]+=dp[f][k][g];
                dp[f^1][k+1][gc[g][i]]%=P;
            }
        }
        f^=1;
    }
    
    int ans=0;
    for(int i=2;i<=n;i++) 
    {
        ans+=dp[f][m][i];
        ans%=P;
    }
    cout<<ans<<"\n";
}

signed main() 
{
    init();
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}

