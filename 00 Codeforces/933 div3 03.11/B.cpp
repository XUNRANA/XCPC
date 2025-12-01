#include <bits/stdc++.h>
using namespace std;
long long n,a[200010];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=2;i<=n-1;i++)
	{
		if(a[i-1]<0)
		{
			cout<<"NO\n";
			return ;
		}
		if(a[i-1]>0) 
		{
			a[i]-=2*a[i-1];
			a[i+1]-=a[i-1];
			a[i-1]-=a[i-1];
		}
	}
	if(a[n]!=0||a[n-1]!=0) cout<<"NO\n";
	else cout<<"YES\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t1;
	cin>>t1;
	while(t1--) solve();
}
