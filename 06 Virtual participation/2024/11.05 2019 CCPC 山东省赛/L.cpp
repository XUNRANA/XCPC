#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 998244353
int C[110][110];
void init()
{
	for(int i=0;i<=100;i++)
	{
		for(int j=0;j<=i;j++)
		{
			if(!j) C[i][j]=1;
			else C[i][j]=(C[i-1][j]+C[i-1][j-1])%P;
		}
	}
}
void solve()
{
	int n,k,m;
	string s,t;
	cin>>n>>k>>m;
	cin>>s;
	cin>>t;
	int cnt=0;
	for(int i=0;i<n;i++) if(s[i]!=t[i]) cnt++;
	
	vector<vector<int>>dp(k+1,vector<int>(n+1,0));
//	cnt 亮 
//	n-cnt 不亮 
	
	dp[0][cnt]=1;//一开始cnt亮
	 
	for(int i=0;i<k;i++)//k轮 
	{	
		for(int j=0;j<=n;j++)//一次翻m个亮的 
		{
			int jj=n-j;
		
			for(int x=0;x<=j&&x<=m;x++)
			{
				int y=m-x;
				if(jj<y) continue;
				dp[i+1][j-x+y]=(dp[i+1][j-x+y]+dp[i][j]*C[j][x]%P*C[jj][y]%P)%P;
			}
			
		}
	}
	
	cout<<dp[k][0]<<"\n"; 
}
signed main()
{
	init();
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
