#include <bits/stdc++.h>
using namespace std;
int n,m,k,a[300010],q[300010],ans[300010];
void solve()
{
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>a[i],ans[i]=0;
	for(int i=1;i<=k;i++) cin>>q[i];
	if(k==n) 
	{
		for(int i=1;i<=m;i++) ans[i]=1;
	}
	else if(k==n-1)
	{
		int val=1;
		for(int i=1;i<=k;i++,val++) 
		if(q[i]!=val) break;
		
		for(int j=1;j<=m;j++)
		if(a[j]==val)
		{
			ans[j]=1;
			break;
		}
			
		
	}
	for(int i=1;i<=m;i++) cout<<ans[i];
	cout<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
