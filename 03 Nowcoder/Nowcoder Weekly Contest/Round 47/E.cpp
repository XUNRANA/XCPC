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
	int n,a,b,c;
	cin>>n;
	a=ksm(4,n);//横对称 0 1 3 8
	b=ksm(4,n/2);//纵队称 2/5 5/2 0/0 8/8
	if(n&1) b=b*2%P;//多一个
	c=ksm(2,n/2);
	if(n&1) c=c*2%P;
	cout<<(a+b-c+P)%P; 
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
