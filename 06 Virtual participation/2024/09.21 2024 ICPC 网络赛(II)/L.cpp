#include <bits/stdc++.h>
using namespace std;

#define int long long
int n;
bool f(int m1,int m2)
{
	return m1*m2>2*n;
} 
int gcd(int a,int b)
{
	return b==0? a:gcd(b,a%b);
}
void solve()
{
	cin>>n;
	if(n==1) cout<<"1 1\n";
	else if(n==2) cout<<"3 2\n";
	else if(n==3) cout<<"2 1\n";
	else
	{
//		for(int i=1;i<=n;i++)
//		{
//			int L=i;
//			int a=(1+L)*L+(n-L)*2;
//			int b=2*L;
//			int g=__gcd(a,b);
//			a/=g;
//			b/=g;
//			cout<<L<<" "<<1.0*a/b<<" "<<a<<" "<<b<<"\n";
//		}
		int L=1,R=n;
		while(L<R)
		{
			int m1=L+(R-L)/3;
			int m2=R-(R-L)/3;
			if(f(m1,m2)) R=m2-1;//f(m1)<f(m2) 极大值时刚好相反 
			else L=m1+1;
		}
		int a=(1+L)*L+(n-L)*2;
		int b=2*L;
		int g=gcd(a,b);
		a/=g;
		b/=g;
		cout<<a<<" "<<b<<"\n";
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
