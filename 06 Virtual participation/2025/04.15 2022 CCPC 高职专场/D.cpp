#include <bits/stdc++.h>
using namespace std;
#define int long long
int a,b,c,l,r;
int fx(int x)
{
	return a*x*x+b*x+c;
} 
void solve()
{
	cin>>a>>b>>c>>l>>r;
	int r1=min(fx(l),fx(r));
	int r2=max(fx(l),fx(r));
	if(!a)
	{
		cout<<r1<<" "<<r2<<"\n";
		return ;
	}
	if(!b)
	{
		cout<<c<<" "<<max(r1,r2)<<"\n";
		return ;
	}
	
	if(a!=0)
	{
		int x1=-b/(2*a);
		int x2=-(b+2*a-1)/(2*a);
		if(x1<=r&&x1>=l) 
		{
			r1=min(r1,fx(x1));
			r2=max(r2,fx(x1));
		}
		if(x2<=r&&x2>=l) 
		{
			r1=min(r1,fx(x2));
			r2=max(r2,fx(x2));
		}
	}
	cout<<r1<<" "<<r2<<"\n";
} 
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

