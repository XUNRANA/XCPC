#include <bits/stdc++.h>
using namespace std;
int a[5010];
int dp[5010];
int n,g,cnt;
int G[5010][5010];
void init()
{
    for(int i=0;i<=5000;i++)
    {
        for(int j=0;j<=5000;j++)
        {
            G[i][j]=__gcd(i,j);
        }
    }
}
void solve()
{
    cin>>n;
    g=cnt=0;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) g=__gcd(g,a[i]);
    for(int i=1;i<=n;i++) cnt+=(g==a[i]);
    if(cnt) cout<<n-cnt<<"\n";
    else 
    {
        for(int i=1;i<=5000;i++) dp[i]=1e9;
        for(int i=1;i<=n;i++)
        {
            for(int x=0;x<=5000;x++)
            {
                int y=G[a[i]][x];
                dp[y]=min(dp[y],dp[x]+1);
            }
        }
        cout<<n-1+dp[g]-1<<"\n";
    }
}

int main() 
{
    init();
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}