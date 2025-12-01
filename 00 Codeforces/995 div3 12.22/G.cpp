#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 1000000007
int a[200010][21][2];
int d[21][21];
int dp[1<<20][21];
//1:伸长
//0:缩放
void solve()
{
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=q;i++)
    {
        int x;
        char ch;
        cin>>x>>ch;
        x--;
        for(int j=0;j<n;j++) 
        {
            a[i][j][0]=a[i-1][j][0];
            a[i][j][1]=a[i-1][j][1];
        }
        if(ch=='+') a[i][x][1]++;
        else a[i][x][0]++;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            for(int k=1;k<=q;k++)
            {
                // cout<<i<<" "<<j<<" "<<-a[k][j][0]+a[k][i][1]+1<<"\n";
                //i后面接j
                d[i][j]=max(d[i][j],-a[k][j][0]+a[k][i][1]+1);
                //j后面接i
                d[j][i]=max(d[j][i],-a[k][i][0]+a[k][j][1]+1);
            }
        }
    }
    // for(int i=0;i<n;i++) for(int j=0;j<n;j++) if(i!=j) cout<<i<<" "<<j<<" "<<d[i][j]<<"\n";
    for(int i=0;i<1<<n;i++) for(int j=0;j<n;j++) dp[i][j]=1e9;
    
    for(int i=0;i<n;i++) dp[1<<i][i]=0;
    

    for(int i=1;i<1<<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i>>j&1)
            {
                for(int k=0;k<n;k++)
                if(k!=j&&(i>>k&1))
                {
                    dp[i][j]=min(dp[i][j],dp[i^(1<<j)][k]+d[k][j]);
                }
            }
        }
    }
    int ans=1e9;
    for(int i=0;i<n;i++) ans=min(ans,dp[(1<<n)-1][i]+a[q][i][1]+1);
    cout<<ans<<"\n";
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}
