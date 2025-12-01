#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
void solve()
{
	cin>>n;
	for(int i=0;i<=60;i++)
	if(n==(1ll<<i)-1)
	{
		cout<<i<<"\n";
		return ;
	}
	cout<<(int)log2(n)<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
