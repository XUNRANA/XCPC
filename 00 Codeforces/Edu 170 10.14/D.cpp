#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[2000010];
int dp[5010][5010][2];
//dp[i][j][1]表示第i个0到第i+1个0之间小于j的有多少个正数 
//dp[i][j][0]表示第i个0到第i+1个0之间大于-j的有多少个负数 
int ans[5010][2];//ans[i]到目前位置 有i次+1 的机会的最大答案 
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==0) cnt++;
		if(a[i]<0) dp[cnt][-a[i]][0]++;
		else if(a[i]>0) dp[cnt][a[i]][1]++;
	}

	for(int i=0;i<=m;i++)
	{
		for(int j=1;j<=m;j++) dp[i][j][0]+=dp[i][j-1][0];

		for(int j=1;j<=m;j++) dp[i][j][1]+=dp[i][j-1][1];
	}
	
	int k=0,s=0;
	while(m--)
	{
		s++; 
		for(int j=0;j<=s;j++) ans[j][k^1]=0;
		for(int j=0;j<=s-1;j++)//用于+1的个数 
		{
			int t=s-(j+1);//用于-1的个数 
			ans[j+1][k^1]=max(ans[j+1][k^1],ans[j][k]+dp[s][t][0]+dp[s][j+1][1]);
			ans[j][k^1]=max(ans[j][k^1],ans[j][k]+dp[s][t+1][0]+dp[s][j][1]);
		}
		k^=1;
	}
	int res=0;
	for(int j=0;j<=s;j++) res=max(res,ans[j][k]);
	cout<<res<<"\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
//    cin>>T;
    while(T--) solve();
}
