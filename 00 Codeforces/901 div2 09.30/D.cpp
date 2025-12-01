#include <bits/stdc++.h>
using namespace std;
int dp[5010];
void solve()
{
	int n,t,k,ans;
	cin>>n;
	map<int,int>m;
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		m[t]++;
	}

	if(m[0]==0)//mex为0 
	{
		cout<<"0\n";
		return ;
	}
	
	for(int i=0;i<=n;i++)
	{
		if(m[i]==0)
		{
			k=i-1;//找到初始mex 
			break;
		}
	}
	/*
	for(int i=0;i<=k;i++) cout<<m[i]<<" ";
	cout<<"\n";
	*/
	for(int i=0;i<=k;i++) dp[i]=1e9;//清空 
	dp[k+1]=0;//dp[i]表示mex为i时的最小代价 
	for(int i=k;i>=0;i--)
	{
		for(int j=i+1;j<=k+1;j++)
		{//从j转移到i，mex代价为m[i]-1个j，加上一个i 
			dp[i]=min(dp[j]+j*(m[i]-1)+i,dp[i]);
		}
	}
	cout<<dp[0]<<"\n";
	
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t1;
	cin>>t1;
	while(t1--) solve(); 
}
