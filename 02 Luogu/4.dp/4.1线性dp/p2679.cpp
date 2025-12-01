#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 1000000007
#define N 1010
#define M 210
char a[N],b[M];
int dp[2][M][M][2];
//dpi，j，p，v考虑a的前i个字符，选出p个字段拼成b的前j个字符，
//v等于0代表选了i，为1代表没有选i 
int n,m,k;
signed main()
{
	cin>>n>>m>>k>>a+1>>b+1;
	dp[0][0][0][0]=dp[1][0][0][0]=1;
	for(int i=1,val=1;i<=n;i++,val^=1)
	{
		for(int j=1;j<=m;j++)
		{
			for(int p=1;p<=k;p++)
			{
				if(a[i]==b[j])
				{
					dp[val][j][p][0]=(dp[val^1][j][p][0]+dp[val^1][j][p][1])%P;
					dp[val][j][p][1]=(dp[val^1][j-1][p][1]+dp[val^1][j-1][p-1][0]+dp[val^1][j-1][p-1][1])%P;
					
				}
				else
				{
					dp[val][j][p][0]=(dp[val^1][j][p][0]+dp[val^1][j][p][1])%P;
					dp[val][j][p][1]=0;
				}
			
			}
		}
	}
	cout<<(dp[n&1][m][k][0]+dp[n&1][m][k][1])%P;
	
}
