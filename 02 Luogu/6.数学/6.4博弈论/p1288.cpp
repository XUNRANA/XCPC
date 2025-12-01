#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[30];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	if(a[i]==0)
	{
		if(i%2==0)
		{
			cout<<"YES\n";
			return ;
		}
		break;
	}
	
	for(int i=n;i>=1;i--)
	if(a[i]==0)
	{
		if((n-i+1)%2==0)
		{
			cout<<"YES\n";
			return ;
		}
		break;
	}
	cout<<"NO\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
