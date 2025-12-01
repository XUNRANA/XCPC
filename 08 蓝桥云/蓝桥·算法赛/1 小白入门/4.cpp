#include <bits/stdc++.h>
using namespace std;
#define int long long
void write(__int128 x)
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
int n,a[100010],s;
void solve()
{
	__int128 ans=0;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],s+=a[i];
	for(int i=1;i<=n;i++)
	{
		s-=a[i];
		ans+=a[i]*s;
	}
	write(ans);
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
} 
