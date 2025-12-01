#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,s,t;
int a[1000010];
int dp[1000010];
void solve()
{
    cin>>n>>s>>t;
    for(int i=1;i<=n;i++) 
    {
        cin>>a[i];
        dp[i]=1e9;
    }
    queue<int>q;
    dp[s]=0;
    q.push(s);
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        if(x-a[x]>=1) 
        {
            if(dp[x]+1<dp[x-a[x]])
            {
                dp[x-a[x]]=dp[x]+1;
                q.push(x-a[x]);
            }
        }
        if(x+a[x]<=n) 
        {
            if(dp[x]+1<dp[x+a[x]])
            {
                dp[x+a[x]]=dp[x]+1;
                q.push(x+a[x]);
            }
        }
    }
    if(dp[t]==1e9) dp[t]=-1;
    cout<<dp[t]<<"\n";

}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}
