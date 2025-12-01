#include <bits/stdc++.h>
using namespace std;
#define int long long 
int n,ans,x,a[25];
void dfs(int s,int res)
{
	if(s==1)
	{
		ans=max(res,ans);
		return ;
	}
	for(int i=1;i<s;i++) dfs(i,res%a[i]);
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	cin>>x;
	ans=0;
	for(int i=1;i<=n;i++) dfs(i,x%a[i]);
	cout<<ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t1=1;
	//cin>>t1;
	while(t1--) solve();
} 
