#include <bits/stdc++.h>
using namespace std;
int n,x;
void solve()
{
	cin>>n>>x;
	vector<int>a(n+2),f(n+2),g(n+2);
	for(int i=1;i<=n;i++) cin>>a[i];
	f[n+1]=g[n+1]=0;
	if(n==1)
	{
		if(x==0||x==a[1]) cout<<"Yes\n";
		else cout<<"No\n";
		return ;
	}
	f[1]=g[1]=a[1];
	for(int i=2;i<=n+1;i++) 
	{
		f[i]=max(f[i-1],f[i-2])+a[i];
		g[i]=min(g[i-1],g[i-2])+a[i];
	}
	if(x>=g[n+1]&&x<=f[n+1]) cout<<"Yes\n";
	else cout<<"No\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t1;
	cin>>t1;
	while(t1--) solve();
}
