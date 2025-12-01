#include <bits/stdc++.h>
using namespace std;

#define int long long
#define P 998244353
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
	int n;
	cin>>n;
	if(n==1) cout<<"1\n";
	else if(n==2) cout<<"2\n";
	else if(n==3) cout<<"6\n";
	else cout<<6*ksm(2,n-3)%P<<"\n"; 
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
