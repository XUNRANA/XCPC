#include <bits/stdc++.h>
using namespace std;
int n,mx;
vector<int>e[20];
vector<pair<string,string>>v(20);
int dp[1<<20][20];
void dfs(int x,int y)
{
	dp[x][y]=1;
	for(auto i:e[y])
	if(x&(1<<i)) continue;//选了跳过 
	else if(!dp[x|(1<<i)][i]) dfs(x|(1<<i),i);//选下一个 
}
int cl(int x)
{
	int s=0;
	while(x)
	{
		s+=x%2;
		x/=2;
	}
	return s;
}
void solve()
{
	cin>>n;
	for(int i=0;i<n;i++) cin>>v[i].first>>v[i].second,e[i].clear();
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(v[i].first==v[j].first||v[i].second==v[j].second)
			{
				e[i].push_back(j);
				e[j].push_back(i);
			}
		}
	}
	
	for(int i=0;i<(1<<n);i++) for(int j=0;j<n;j++) dp[i][j]=0;
	for(int i=0;i<n;i++) dfs(1<<i,i);
	mx=0;
	for(int i=0;i<(1<<n);i++) for(int j=0;j<n;j++) if(dp[i][j]) mx=max(mx,cl(i));
	cout<<n-mx<<"\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--) solve();	
}
