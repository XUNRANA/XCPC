#include <bits/stdc++.h>
using namespace std;
int n,m,k,dp[200010],f[200010];
string s;
void solve()
{
	cin>>n>>m>>k>>s;
	dp[0]=0;
	
	for(int i=1;i<=n+1;i++) dp[i]=1e9,f[i]=0;
	
	s="L"+s+"L";
	for(int i=n;i>=1;i--) if(s[i]=='W'&&s[i+1]=='C') s[i]='C'; 
	
	for(int i=n;i>=1;i--) 
	if(s[i]=='W') 
	{
		if(s[i+1]=='W') f[i]=f[i+1]+1;
		else f[i]=1;
	}
	
	for(int i=1;i<=n+1;i++)
	{
		if(s[i]=='L')
		{
			for(int j=max(0,i-m);j<i;j++)
			{
				if(s[j]=='L') dp[i]=min(dp[i],dp[j]);
			}
		}
		else if(s[i]=='W')
		{
			for(int j=max(0,i-m);j<i;j++)
			{
				if(s[j]=='L') 
				{
					dp[i]=min(dp[i],dp[j]);
					dp[i+f[i]]=min(dp[i+f[i]],dp[j]+f[i]);
				}
			}
		}
	}
	if(dp[n+1]<=k) cout<<"YES\n";
	else cout<<"NO\n";

}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--) solve();
}
