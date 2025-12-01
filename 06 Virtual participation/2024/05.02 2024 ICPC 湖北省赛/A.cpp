#include <bits/stdc++.h>
using namespace std;
#define int long long
int gcd(int x,int y)
{
	return y==0? x:gcd(y,x%y);
}
void solve()
{
	int x,y,z;
	cin>>x>>y;
	z=gcd(x,y);
	x/=z;
	y/=z;
	cout<<1<<" "<<x*y<<"\n";
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
