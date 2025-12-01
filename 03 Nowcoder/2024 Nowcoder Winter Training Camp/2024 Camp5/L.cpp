#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	int n,x;
	cin>>n>>x;
	for(int i=0;i<=n;i++)
	{
		int a=i;
		int b=n-i;
		if(a-b==x)
		{
			cout<<a<<" "<<b<<"\n";
			return ;
		}
	}
	cout<<"-1\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
