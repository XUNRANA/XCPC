#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vv vector
void solve()
{
    string s;
	cin>>s;
	s=" "+s;
    ll n=s.size()-1;
    vv<vv<ll>> dp(n+1,vv<ll>(n+1));
    ll ans=0;
    for(ll i=1;i<=n;++i)
	{
        vv<ll> vis(n+1);
        for(ll j=i+1;j<=n;++j) if(s[j]==s[i]||s[j]=='?'||s[i]=='?') vis[j-i]=1;
        for(ll j=1;j<=n;++j)
        if(vis[j])
		{
            dp[i][j]=dp[i-1][j]+1;
            if(dp[i][j]>=j) ans=max(ans,2*j);
        }
    }
    for(int i=1;i<=n;i++,cout<<"\n")
    {
    	for(int j=1;j<=n;j++) cout<<dp[i][j]<<" ";
	}
    cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t1;
	cin>>t1;
	while(t1--) solve();
}
