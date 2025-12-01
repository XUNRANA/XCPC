#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,t;
string s;
int c[26][26];
int dp[1<<21][21];
int fx(int i,int j,int k)
{
    int c=0;
    for(int ii=j;ii<=k;ii++)
    {
        if(i>>ii&1) c++;
    }
    return c;
}
void solve()
{
    cin>>n>>m>>t;
    cin>>s;
    for(int i=0;i<m;i++) for(int j=0;j<m;j++) cin>>c[i][j];
    for(int i=0;i<(1<<n);i++) for(int j=0;j<n;j++) dp[i][j]=1e9;
    for(int i=0;i<n;i++) dp[1<<i][i]=c[0][s[i]-'a']+t;
    for(int i=1;i<(1<<n);i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i>>j&1)
            {
                for(int k=0;k<n;k++)
                if(k!=j&&(i>>k&1))//k ---->j
                {
                    if(j<k) dp[i][j]=min(dp[i][j],dp[i^(1<<j)][k]+c[s[k]-'a'][s[j]-'a']+t*fx(i^(1<<j),j,k)+t);
                    else dp[i][j]=min(dp[i][j],dp[i^(1<<j)][k]+c[s[k]-'a'][s[j]-'a']+t*fx(i^(1<<j),k+1,j)+t);
                }
            }
        }
    }
    int ans=1e9;
    for(int j=0;j<n;j++) ans=min(ans,dp[(1<<n)-1][j]);
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