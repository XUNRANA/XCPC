#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 998244353
int n,dp[200010][2],a[200010];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    dp[1][0]=1;//Lied
    if(a[1]==0) dp[1][1]=1;//Honesty
    else dp[1][1]=0;// not Honesty
    for(int i=2;i<=n;i++) 
    {
        dp[i][0]=dp[i-1][1];
        dp[i][1]=0;
        if(a[i]==a[i-1]) dp[i][1]+=dp[i-1][1];
        dp[i][1]%=P;
        if(a[i]==a[i-2]+1) dp[i][1]+=dp[i-1][0];   
        dp[i][1]%=P;     
    }
    cout<<(dp[n][0]+dp[n][1])%P<<"\n";
}
signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
