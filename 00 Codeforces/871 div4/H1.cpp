#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 1000000007
int dp[200010][64];
void solve()
{
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        for(int j=0;j<64;j++) dp[i][j]=0;
        dp[i][x]=1;
        for(int j=0;j<64;j++)
        {
            dp[i][j]=(dp[i-1][j]+dp[i][j])%P;
            dp[i][j&x]=(dp[i-1][j]+dp[i][j&x])%P;
        }
    }
    int ans=0;
    for(int i=0;i<64;i++) if(__builtin_popcount(i)==k) ans=(dp[n][i]+ans)%P;
    cout<<ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
} 
