#include <bits/stdc++.h>
using namespace std;
#define int long long 
int n,m,k,a,b,dp[5050],dis[5050];
void solve()
{
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) dp[i]=dis[i]=1e18;
    dp[k]=0;
	for(int i=1;i<=m;i++)
	{
		cin>>a>>b;
		for(int j=1;j<=n;j++) dis[a*j%n]=min(dis[a*j%n],j*b);
	}

	for(int i=1;i<=n;i++) 
    {
        for(int j=1;j<=n;j++) 
        {//取模，更新没有滞后性 
            dp[(j+i-1)%n+1]=min(dp[(j+i-1)%n+1],dp[j]+dis[i]);
        }
    }
	if(dp[n]==1e18) cout<<-1<<"\n";
	else cout<<dp[n]<<"\n";
}
signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
    while(T--) solve();
}
