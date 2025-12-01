#include <bits/stdc++.h>
using namespace std;
int a[110];
void solve()
{
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	while(k--)
	{
		int u,v;
		cin>>u>>v;
		a[u]++;
		a[v]--;
	}
	for(int i=1;i<n;i++) 
	if(a[i]>a[i+1]) 
	{
		cout<<"No\n";
		return ;
	}
	cout<<"Yes\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
