#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k,a[200010];
void solve()
{
	cin>>n>>k;
	if(k==0)
	{
		if(n<=2)
		{
			cout<<"-1\n";
			return ;
		}
		for(int i=1;i<=n;i++) cout<<i<<" "<<i<<" ";
		cout<<"\n";
		return ;
	}
	
	if(k==1)
	{
		if(n==1) cout<<"-1\n";
		else
		{
			a[1]=1;
			for(int i=2;i<=n+1;i++) a[i]=i-1;
			for(int i=n+2;i<=2*n;i++) a[i]=i-n;
			for(int i=1;i<=2*n;i++) cout<<a[i]<<" ";
			cout<<"\n";
		}
		return ;
	}

	int j=1;
	for(int i=1;i<=n+k-2;i++) 
	{
		a[i]=j++;
		if(j>n) j=1;
	}
	for(int i=1;i<=2*n;i++)
	{
		if(!a[i])
		{
			a[i]=n;
			for(int k1=i+1;k1<=2*n;k1++)
			{
				a[k1]=j++;
			}
			break;
		}
	}
	for(int i=1;i<=2*n;i++) cout<<a[i]<<" ";
	cout<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
