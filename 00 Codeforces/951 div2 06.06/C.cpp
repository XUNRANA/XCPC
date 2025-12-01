#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,s,a[51],b[51],l;
int gcd(int x,int y)
{
	return y==0? x:gcd(y,x%y);
}
int lcm(int x,int y)
{
	return x*y/gcd(x,y);
}
void solve()
{
	cin>>n;
	s=0;
	l=1;
	for(int i=1;i<=n;i++) cin>>a[i],l=lcm(l,a[i]);
	for(int i=1;i<=n;i++) b[i]=l/a[i],s+=b[i];
	if(l<=s)
	{
		cout<<"-1\n";
		return ;
	}
	for(int i=1;i<=n;i++) cout<<b[i]<<" ";
	cout<<"\n";
	// 3  4  6 8 9 
	//24 18 12 9 8
	
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
