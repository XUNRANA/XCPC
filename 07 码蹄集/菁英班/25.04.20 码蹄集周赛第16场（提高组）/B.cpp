#include <bits/stdc++.h>
using namespace std;
#define int long long
int dp[1<<16][3];
//0:head
//1:tail
//2:length
string s[16];
void solve() 
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>s[i];
    
    for(int i=0;i<(1<<n);i++)
    {
        for(int j=0;j<n;j++)
        if(i>>j&1)
        {
            int pre=i^(1<<j);
            if(pre==0)
            {
                dp[i][0]=s[j][0];
                dp[i][1]=s[j].back();
                dp[i][2]=s[j].size();
            }
            else
            {
                if(dp[pre][0]==s[j].back())
                {
                    dp[i][0]=s[j][0];
                    dp[i][1]=dp[pre][1];
                    dp[i][2]=dp[pre][2]+s[j].size();
                }
                else if(dp[pre][1]==s[j][0])
                {
                    dp[i][0]=dp[pre][0];
                    dp[i][1]=s[j].back();
                    dp[i][2]=dp[pre][2]+s[j].size();
                }
            }
        }
    }
    int ans=0;
    for(int i=0;i<(1<<n);i++) ans=max(ans,dp[i][2]);
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