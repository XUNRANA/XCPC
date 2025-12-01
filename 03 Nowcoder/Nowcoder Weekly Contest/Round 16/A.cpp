#include <bits/stdc++.h>
using namespace std;
int n,a[100010],b[100010];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<n;i++) b[i]=a[i+1]-a[i];
	for(int i=2;i<=n;i++) if(a[i-1]>=a[i]) 
	{
		cout<<"No\n";
		return ;
		
	}
	for(int i=2;i<n;i++) if(b[i-1]<=b[i]) 
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
	//cin>>T;
	while(T--) solve();
}
