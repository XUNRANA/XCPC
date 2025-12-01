#include <bits/stdc++.h>
using namespace std;
#define int long long
const int P=1000000007;
int ksm(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1) res=res*a%P;
		a=a*a%P;
		b>>=1;
	}
	return res;
}
void solve()
{
	int n,p,q;
	cin>>n>>p>>q;
	cout<<ksm(p*ksm(q,P-2)%P,n)<<'\n';
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
