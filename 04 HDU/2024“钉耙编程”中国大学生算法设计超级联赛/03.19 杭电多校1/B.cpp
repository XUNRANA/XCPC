
#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n,k;
    cin>>n>>k;
    vector<int>dp(k+1,1e18);
    dp[0]=0;
    while(n--)
    {
        vector<int>b(5,0);
        for(int i=1;i<=4;i++) cin>>b[i];
        vector<int>ndp=dp;
        for(int i=0;i<=k;i++) 
        {
            for(int j=1;j<=4;j++)
            {
                if(i+j<=k)
                {
                    ndp[i+j]=min(ndp[i+j],dp[i]+b[j]);
                }
            }
        }
        dp=ndp;
    }
    cout<<dp[k]<<"\n";

} 
 
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}