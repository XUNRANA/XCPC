#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 1000000007
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
	int n,t;
	cin>>n;
	vector<int>c(4);
	for(int i=1;i<=n;i++) cin>>t,c[t]++;
	cout<<ksm(2,n-2)*(c[2]+2)%P*(c[3]+2)%P-1;
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
