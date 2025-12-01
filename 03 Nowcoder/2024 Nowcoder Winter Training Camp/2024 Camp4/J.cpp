#include <bits/stdc++.h>
using namespace std;
#define int long long
struct node
{
	int x,y; 
}p[30];
int n,dp[(1<<21)],f[30][30];
bool ck(node p1,node p2,node p3)
{
	int dx1=p2.x-p1.x;
	int dy1=p2.y-p1.y;
	int dx2=p3.x-p2.x;
	int dy2=p3.y-p2.y;
	if(dx1*dy2==dy1*dx2) return 1;
	return 0;
}
void solve()
{
	cin>>n;
	for(int i=0;i<(1<<n);i++) dp[i]=n;
	for(int i=0;i<n;i++) cin>>p[i].x>>p[i].y;
	for(int i=0;i<n;i++) dp[1<<i]=1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i!=j) for(int k=0;k<n;k++) if(ck(p[i],p[j],p[k])) f[i][j]|=1<<k;
			else f[i][j]|=1<<i;
			dp[f[i][j]]=1; 
		}
	}
	for(int i=1;i<(1<<n);i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i>>j&1)
			{
				for(int k=0;k<n;k++) dp[i|f[j][k]]=min(dp[i|f[j][k]],dp[i]+1);
			}
		}
	}
	cout<<dp[(1<<n)-1];
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
