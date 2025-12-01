#include <bits/stdc++.h>
using namespace std;
int n,ans,a[1010],s[1010];
int is(int x)
{
	for(int i=2;i*i<=x;i++)
	{
		if(x%i==0) return 1;
	}
	return 0;
}
void solve()
{
	ans=1e9;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],s[i]=s[i-1]+a[i];
	if(n==1)
	{
		if(is(a[1])) cout<<"0\n";
		else cout<<"-1\n";
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(is(s[j]-s[i-1]))
			{
				ans=min(j-i,ans);
				break;
			}
		}
	}
	if(ans==1e9) ans=-1;
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
