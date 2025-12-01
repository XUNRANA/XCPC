#include <bits/stdc++.h>
using namespace std;
#define int long long
bool ck(int x,int i)
{
	while(x)
	{
		if(x%i>1) return 0;
		x/=i;
	}
	return 1;
}
void solve()
{
	int k1,k2;
	cin>>k1>>k2;
	for(int i=max(k1,k2);i<=max(k1,k2)+1000000;i++)
	{
		if(ck(i,k1)&&ck(i,k2))
		{
			cout<<"YES\n";
			cout<<i<<"\n";
			return ;
		}
	}
	cout<<"NO\n";
}

signed main()
{
//	cout<<(1ll<<19)<<"\n";
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
