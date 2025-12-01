#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,ans,a[10010];
void solve()
{
	ans=0;
	cin>>n;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		if(a[i]==1) a[i]=2;
	}
	for(int i=1;i<=n-1;i++) if(a[i+1]%a[i]==0) a[i+1]++;
	for(int i=1;i<=n;i++) cout<<a[i]<<" ";
	cout<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
}
