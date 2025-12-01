#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k;
int x[11];
int y[11];
int dp[110][110];
int a[110][110];
int dis(int x,int y,int xx,int yy)
{
    return abs(x-xx)+abs(y-yy);
}
int fx(int mask)
{
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) dp[i][j]=1e9;
    for(int i=0;i<k;i++)
    {
        if(mask>>i&1)
        {//向下走
            if(x[i]==n) return -1;
            if(i==0)
            {
                for(int i1=x[i]+1;i1<=n;i1++)
                dp[i1][y[i]]=y[i]-1;
            }
            else
            {
                if(y[i]-y[i-1]>1)
                {
                    for(int i1=x[i]+1;i1<=n;i1++)
                    for(int i2=1;i2<=n;i2++)
                    dp[i1][y[i]]=min(dp[i1][y[i]],dp[i2][y[i-1]]+dis(i2,y[i-1],i1,y[i]));
                }
                else
                {
                    for(int i1=x[i]+1;i1<=n;i1++)
                    {
                        int p=(mask>>(i-1))&1;
                        if(p)
                        {
                            for(int i2=x[i-1]+1;i2<=n;i2++)
                            dp[i1][y[i]]=min(dp[i1][y[i]],dp[i2][y[i-1]]+dis(i2,y[i-1],i1,y[i]));
                        }
                        else
                        {
                            if(x[i-1]-x[i]>1)
                            {
                                for(int i2=1;i2<=x[i-1]-1;i2++)
                                dp[i1][y[i]]=min(dp[i1][y[i]],dp[i2][y[i-1]]+dis(i2,y[i-1],i1,y[i]));
                            }
                        }
                    }
                }
            }
        }
        else
        {
            if(x[i]==1) return -1;
            if(i==0)
            {
                for(int i1=1;i1<=x[i]-1;i1++)
                dp[i1][y[i]]=y[i]-1;
            }
            else
            {
                if(y[i]-y[i-1]>1)
                {
                    for(int i1=1;i1<=x[i]-1;i1++)
                    for(int i2=1;i2<=n;i2++)
                    dp[i1][y[i]]=min(dp[i1][y[i]],dp[i2][y[i-1]]+dis(i2,y[i-1],i1,y[i]));
                }
                else
                {
                    for(int i1=1;i1<=x[i]-1;i1++)
                    {
                        int p=(mask>>(i-1))&1;
                        if(!p)
                        {
                            for(int i2=1;i2<=x[i-1]-1;i2++)
                            dp[i1][y[i]]=min(dp[i1][y[i]],dp[i2][y[i-1]]+dis(i2,y[i-1],i1,y[i]));
                        }
                        else
                        {
                            if(x[i]-x[i-1]>1)
                            {
                                for(int i2=x[i-1]+1;i2<=n;i2++)
                                dp[i1][y[i]]=min(dp[i1][y[i]],dp[i2][y[i-1]]+dis(i2,y[i-1],i1,y[i]));
                            }
                        }
                    }
                }
            }
        }
    }

    int ans=1e9;
    for(int i=1;i<=n;i++) ans=min(ans,dp[i][y[k-1]]+m-y[k-1]);
    
    if(ans==1e9) ans=-1;
    return ans;
}
void solve()
{
    cin>>n>>m>>k;
    if(k==0) 
    {
        cout<<m-1<<"\n";
        return ;
    }
    for(int i=0;i<k;i++) cin>>x[i]>>y[i];
    for(int i=0;i<(1<<k);i++) cout<<fx(i)<<" ";
    cout<<"\n";    
}
signed main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}