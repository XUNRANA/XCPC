#include <bits/stdc++.h>
using namespace std;
#define int long long
int a,n,ans,l[1000010];
int lcm(int x,int y)
{
	return x*y/__gcd(x,y);
}
void init()
{
	l[1]=1;
	for(int i=2;i<=1e6;i++)
	{
		l[i]=lcm(l[i-1],i);
		if(l[i]>1e16) break;
	}
}
void solve()
{
	ans=0;
	cin>>a>>n;
	if(l[a]) ans-=n/l[a];
	if(l[a-1]) ans+=n/l[a-1];
	if(a==1) ans=0;
	cout<<ans<<"\n";
}
signed main()
{
	init();
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
} 
