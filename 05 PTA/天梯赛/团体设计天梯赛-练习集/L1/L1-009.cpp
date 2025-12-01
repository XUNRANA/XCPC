#include <bits/stdc++.h>
using namespace std;
#define int long long
int fz(int a,int b,int c,int d)
{
	int x=a*d+b*c;
	int y=b*d;
	int g=__gcd(x,y);
	x/=g;
	y/=g;
	return x;
}
int fm(int a,int b,int c,int d)
{
	int x=a*d+b*c;
	int y=b*d;
	int g=__gcd(x,y);
	x/=g;
	y/=g;
	return y;
}
void solve()
{
	int n,a,b,c,d,a1,b1;
	scanf("%lld",&n);
	scanf("%lld/%lld",&a,&b);
	for(int i=2;i<=n;i++)
	{
		scanf("%lld/%lld",&c,&d);
		a1=fz(a,b,c,d);
		b1=fm(a,b,c,d);
		a=a1;
		b=b1;
	}
	if(a%b==0) cout<<a/b<<"\n";
	else if(a<b) cout<<a<<"/"<<b<<"\n";
	else cout<<a/b<<" "<<a%b<<"/"<<b<<"\n";
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

