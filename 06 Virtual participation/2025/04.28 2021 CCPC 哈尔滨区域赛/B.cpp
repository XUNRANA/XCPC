#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
int a[100010];
void solve() 
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    int ans=0;
    for(int x=2;x<=200;x++)
    {
        vector<int>dp(n+1),pos(210,-1);
        for(int i=1;i<=n;i++)
        {
            dp[i]=dp[i-1];
            if(x-a[i]>=1&&pos[x-a[i]]!=-1)
            {
                dp[i]=max(dp[i],dp[pos[x-a[i]]-1]+2);
            }
            pos[a[i]]=i;
        }
        ans=max(ans,dp[n]);
    }
    cout<<ans<<"\n";
}


int32_t main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
