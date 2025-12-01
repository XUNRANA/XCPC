#include <bits/stdc++.h>
using namespace std;
int n,a[200010],ans;
void solve()
{
	ans=0;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		if(a[i]==1) a[i]=2;
		if(a[i]==3) a[i]=4;
		if(a[i]>4) 
		{
			a[i]=0;
			ans++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==4)
		{
			if(i+1<=n&&a[i+1]==4)
			{
				ans++;
				a[i]=2;
				i++;
				a[i]=2;
			}
			else
			{
				ans++;
				a[i]=0;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]==2)
		{
			ans++;
			i++;
		}
	}
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--) solve();
}
