#include <bits/stdc++.h>
using namespace std;
#define P 1000000007
#define int long long
int n,x,y,a,b,ans;
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
	cin>>n>>x>>y;
	while(n--)
	{
		cin>>a>>b;
		if(a<x||b>y) continue;
		ans++;
	}
	cout<<(ksm(2,ans)-1+P)%P<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
