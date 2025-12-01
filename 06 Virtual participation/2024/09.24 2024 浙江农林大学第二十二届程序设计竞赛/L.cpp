#include <bits/stdc++.h>
using namespace std;
int n,h,a[200010],s[200010];
void solve()
{
	cin>>n>>h;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s[i]=s[i-1]+a[i];
	}
	
	int sum=s[n];
	int x=sum-h;
	int ans=1e9;
	for(int i=1,j=1;j<=n;j++)
	{
		while(s[j]-s[i-1]>x)
		{
			i++;
			ans=min(ans,sum-(s[j]-s[i-1]));
		}
	}
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
