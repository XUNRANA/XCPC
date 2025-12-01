#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[6];
void solve()
{
	for(int i=1;i<=5;i++) cin>>a[i];
	sort(a+1,a+1+5);
	if(a[1]==a[3]&&a[3]!=a[4]&&a[4]==a[5])
	{
		cout<<"YES\n";
		return ;
	}
	if(a[1]==a[2]&&a[2]!=a[3]&&a[3]==a[5])
	{
		cout<<"YES\n";
		return ;
	}
	cout<<"NO";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
