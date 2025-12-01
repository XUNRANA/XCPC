#include <bits/stdc++.h>
using namespace std;
#define int long long
int f(int x)
{
	int s=0;
	while(x)
	{
		s+=x%10;
		x/=10;
	}
	return s;
}
void solve()
{
	int a,b,fa,fb;
	cin>>a>>b;
	fa=f(a);
	fb=f(b);
	if(a%fb==0&&b%fa==0)
	{
		if(a>b) cout<<"A\n";
		else cout<<"B\n";
	}
	else if(a%fb==0) cout<<"A\n";
	else if(b%fa==0) cout<<"B\n";	
	else 
	{
		if(a>b) cout<<"A\n";
		else cout<<"B\n";
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

