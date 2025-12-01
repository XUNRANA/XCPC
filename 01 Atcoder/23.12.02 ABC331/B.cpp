#include <bits/stdc++.h>
using namespace std;
int dp[110];
int main()
{
	int N,S,M,L;
	cin>>N>>S>>M>>L;
	for(int i=1;i<=6;i++) dp[i]=min(min(S,M),L);
	for(int i=7;i<=8;i++) dp[i]=min(min(M,L),2*S);
	for(int i=9;i<=12;i++) dp[i]=min(2*min(S,M),L);
	for(int i=13;i<=N;i++)
	{
		if(!dp[i]) dp[i]=dp[i-1]+min(min(S,M),L);
		if(i>=6) dp[i]=min(dp[i],dp[i-6]+S);
		if(i>=8) dp[i]=min(dp[i],dp[i-8]+M);
		if(i>=12) dp[i]=min(dp[i],dp[i-12]+L);
	}
	cout<<dp[N];	
} 
