#include <bits/stdc++.h>
using namespace std;
#define N 1000010
#define int long long
#define P 1000000007
//other:0
// r:1
// re:2
// red:3
// red....r:4
// red....re:5
// red....red:6
int dp[7][2];
void solve()
{
	int n;
	cin>>n;
	if(n<6) 
    {
        cout<<"0\n";
        return ;
    }
	dp[0][0]=25;
	dp[1][0]=1;
	int j=0;
	for(int i=2;i<=n;i++,j^=1)
	{                      
		dp[0][j^1]=(dp[0][j]*25+dp[1][j]*24+dp[2][j]*24)%P;
		            
		dp[1][j^1]=(dp[0][j]+dp[1][j]+dp[2][j])%P;
		          
		dp[2][j^1]=dp[1][j];
		         
		dp[3][j^1]=(dp[2][j]+dp[3][j]*25+dp[4][j]*24+dp[5][j]*24)%P;
		
		dp[4][j^1]=(dp[3][j]+dp[4][j]+dp[5][j])%P;
		
		dp[5][j^1]=dp[4][j];
		
		dp[6][j^1]=(dp[5][j]+dp[6][j]*26)%P;
//		cout<<i<<"\n";
//		for(int i=0;i<7;i++) cout<<i<<" "<<dp[i][j^1]<<"\n";
	}
	cout<<dp[6][j]<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

