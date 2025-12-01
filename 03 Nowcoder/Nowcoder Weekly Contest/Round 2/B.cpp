#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[100010];
void solve()
{
    string s;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    cin>>s;
    s=" "+s;
    vector<int>dp(n+1);
    for(int i=2;i<=n;i++)
    {
        dp[i]=dp[i-1];
        if(s[i]!=s[i-1])
        {
            dp[i]=max(dp[i],dp[i-2]+a[i-1]+a[i]);
        }
    }
    cout<<dp[n]<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
