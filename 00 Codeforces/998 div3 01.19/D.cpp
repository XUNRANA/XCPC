#include <bits/stdc++.h>
using namespace std;
int n,a[200010];
void solve()
{

	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	
	for(int i=1;i<n;i++)
	{
		int t=min(a[i],a[i+1]);
		a[i]-=t;
		a[i+1]-=t;
	}
	for(int i=2;i<=n;i++) if(a[i]<a[i-1])
	{
		cout<<"NO\n";
		return ;
	}
	cout<<"YES\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
