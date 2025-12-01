#include <bits/stdc++.h>
using namespace std;
int n,m;
bool dp[5001][5001];//节省运算时间 
void solve()
{
	cin>>n>>m;
	if(dp[n][m]) cout<<"Alice\n";
	else cout<<"Bob\n";
}
void init()
{
	for(int i=0;i<=5000;i++)
	for(int j=0;j<=5000;j++)
	{
		if(dp[i][j]==0)
		{
			for(int k=1;k+i<=5000;k++) for(int s=0;s*k+j<=5000;s++) dp[i+k][j+s*k]=1;
			for(int k=1;k+j<=5000;k++) for(int s=0;s*k+i<=5000;s++) dp[i+s*k][j+k]=1;
		}
	} 
}
int main()
{
    ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	init(); 
	int T=1;
	cin>>T;
	while(T--) solve();
}
