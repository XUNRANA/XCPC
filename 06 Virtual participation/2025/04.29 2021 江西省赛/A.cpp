#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define P 998244353
char a[510][510];
void solve() 
{
    int n,m,p,q;
    cin>>n>>m>>p>>q;
    vector<vector<vector<ll>>>dp(2,vector<vector<ll>>(m+1,vector<ll>(n+m,0)));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j];
        }
    }
    if(a[1][1]=='1') dp[1][1][1]=1;
    else dp[1][1][0]=1;
    
    int f=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(j+1<=m)
            {
                if(a[i][j+1]=='1')
                {
                    for(int k=1;k<min(n+m,i+j+1);k++)
                    {  
                        dp[f][j+1][k]+=dp[f][j][k-1];
                        dp[f][j+1][k]%=P;
                    }
                }
                else 
                {
                    for(int k=0;k<min(n+m,i+j+1);k++)
                    {  
                        dp[f][j+1][k]+=dp[f][j][k];
                        dp[f][j+1][k]%=P;
                    }
                }
            }
            if(i+1<=n)
            {
                if(a[i+1][j]=='1')
                {
                    for(int k=1;k<min(n+m,i+j+1);k++)
                    {  
                        dp[f^1][j][k]+=dp[f][j][k-1];
                        dp[f^1][j][k]%=P;
                    }
                }
                else 
                {
                    for(int k=0;k<min(n+m,i+j+1);k++)
                    {  
                        dp[f^1][j][k]+=dp[f][j][k];
                        dp[f^1][j][k]%=P;
                    }
                }
            }
        }
        if(i!=n)
        {
            for(int j=1;j<=m;j++) for(int k=0;k<min(n+m,i+j);k++) dp[f][j][k]=0;
            f^=1;
        }
    }

    ll ans=0;
    for(int i=q;n+m-1-i>=p;i++) 
    {
        ans+=dp[f][m][i];
        ans%=P;
    }
    cout<<ans<<"\n";
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
