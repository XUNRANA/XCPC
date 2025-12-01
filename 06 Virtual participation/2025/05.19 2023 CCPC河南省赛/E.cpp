#include <bits/stdc++.h>
using namespace std;

int n,m,x;
int a[501][501];
int dp[2][501][1001];
void solve()
{
    cin>>n>>m>>x;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            char ch;
            cin>>ch;
            if(ch=='1') a[i][j]=1;
            else if(ch=='0') a[i][j]=0;
            else a[i][j]=-1;
        }
    }

    for(int i=1;i<=m;i++) for(int j=0;j<=x;j++) dp[1][i][j]=dp[0][i][j]=0;
    
    int f=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i][j]!=-1)
            {
                for(int k1=0;k1<=x;k1++)
                {
                    dp[f][j][k1]=max(dp[f^1][j][k1],dp[f][j-1][k1])+(a[i][j]==1);
                }
            }
            else 
            {
                dp[f][j][0]=max(dp[f^1][j][0],dp[f][j-1][0]);
                for(int k1=1;k1<=x;k1++)
                {
                    dp[f][j][k1]=max(dp[f^1][j][k1-1],dp[f][j-1][k1-1])+1;
                }
            }
        }
        f^=1;
    }
    cout<<dp[f^1][m][x]<<"\n";
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}