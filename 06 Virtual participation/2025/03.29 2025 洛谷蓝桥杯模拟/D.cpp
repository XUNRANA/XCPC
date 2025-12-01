#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 998244853
int n,m;
int a[100010];
int p[100010];
int dp[1010][2];
void solve() 
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>p[i];
    int f=0;
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<m;j++) dp[j][f^1]=0;
        for(int j=0;j<m;j++) 
        {
            dp[(j+a[i])%m][f^1]+=dp[j][f]*p[i]%P;
            dp[(j+a[i])%m][f^1]%=P;
            dp[j][f^1]+=dp[j][f]*(1-p[i]+P)%P;
            dp[j][f^1]%=P;
            
        }
        f^=1;
    }
    cout<<dp[0][f]<<"\n";
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}