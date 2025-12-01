#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[10][10];
int ans,t1,t2,t3;
void dfs(int i)
{
	if(i==6)
	{
		ans=min(ans,max({t1,t2,t3}));
		return ;
	}
	t1+=a[1][i];
	dfs(i+1);
	t1-=a[1][i];
	
	t2+=a[2][i];
	dfs(i+1);
	t2-=a[2][i];
	
	t3+=a[3][i];
	dfs(i+1);
	t3-=a[3][i];
}
void solve()
{
	for(int i=1;i<=3;i++)
	{
		for(int j=1;j<=5;j++)
		{
			cin>>a[i][j];
		}
	}
	t1=t2=t3=0;
	ans=1e18;
	dfs(1);
	cout<<ans<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
