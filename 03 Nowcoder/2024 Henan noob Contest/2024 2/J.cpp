#include <bits/stdc++.h>
using namespace std;
int n,m,a[6][6];
vector<int>path;
vector<int>vt(6);
vector<vector<int>>permutation;
void dfs(int k)
{
	if(path.size()==k)
	{
		permutation.push_back(path);
		return ;
	}
	for(int i=1;i<=k;i++)
	{
		if(!vt[i])
		{
			path.push_back(i);
			vt[i]=1;
			dfs(k);
			vt[i]=0;
			path.pop_back();
		}
	}
}
int nxd(vector<int>a)
{
	int cnt=0;
	for(int i=0;i<a.size();i++)
	{
		for(int j=i+1;j<a.size();j++)
		{
			if(a[j]<a[i]) cnt++;
		}
	}
	return cnt;
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>a[i][j];
	if(n<=m) for(int i=n+1;i<=m;i++) for(int j=1;j<=m;j++) a[i][j]=0;
	else for(int j=m+1;j<=n;j++) for(int i=1;i<=n;i++) a[i][j]=0;
	n=m=max(n,m);
	int ans=1e9;
	for(int k=1;k<=n;k++)
	{
		permutation.clear();
		path.clear();
		for(int i=1;i<=k;i++) vt[i]=0;
		dfs(k);
		int res=0;
		for(auto i:permutation)
		{
			int t=1,r=1;
			for(auto j:i) r*=a[t++][j];
			if(nxd(i)&1) res-=r;
			else res+=r;
		}
		ans=min(ans,res);
	}
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
} 
