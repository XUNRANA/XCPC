#include <bits/stdc++.h>
using namespace std;
#define int long long
bool ck(__int128 x,__int128 k)
{
	return (1+x)*x<k;
}
void solve()
{
	int k;
	cin>>k;
	int l=1,r=1e18;
	while(l<=r)
	{
		int m=l+r>>1;
		if(ck(m,k)) l=m+1;
		else r=m-1;
	}
	cout<<k+l<<"\n";

}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
