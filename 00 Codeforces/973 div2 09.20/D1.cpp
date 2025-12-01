#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200010],s[200010];
int x,y,ss;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],s[i]=s[i-1]+a[i];
	x=a[1];
	y=0;
	ss=0;
	for(int i=1;i<=n;i++) 
	{
//		cout<<i<<" "<<s[i]/i<<" "<<x<<"\n";
		x=min(x,s[i]/i);
	}
	for(int j=n;j>=1;j--) 
	{
		ss+=a[j];
		y=max(y,(ss+n-j)/(n-j+1));
//		cout<<j<<" "<<(ss+n-j)/(n-j+1)<<" "<<y<<"\n";
	}
//	cout<<x<<" "<<y<<" "<<y-x<<"\n";
	cout<<y-x<<"\n";
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
