#include<bits/stdc++.h>
using namespace std;
int w[3000],v[3000],dp[3000];
int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
    {
		cin>>w[i]>>v[i];
		w[i]+=w[i-1];
		v[i]+=v[i-1];
	}
	for(int i=0;i<=k-1;i++)
    {
		for(int j=k;j<=n;j++)
        {
			int W=w[j]-w[i];//选一个连续的区间 必须包含k 
			int V=v[j]-v[i];
			for(int v=W;v<=m;v++) dp[v]=max(dp[v],dp[v-W]+V);
		}
	}
	for(int i=1;i<=m;i++) cout<<dp[i]<<" ";
 } 