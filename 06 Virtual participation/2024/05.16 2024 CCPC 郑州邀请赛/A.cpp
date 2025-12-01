#include <bits/stdc++.h>
using namespace std;
#define int long long
int fx(int x)
{
	int c=0;
	while(x)
	{
		c++;
		x/=10;
	}
	return c;
}
int a[20];
void solve()
{
	int n,d,ans;
	cin>>n>>d;
	int cnt=fx(n);
	int b=(1234567890+d)*a[cnt];
	b+=n-b%n;
	cout<<b/n<<'\n';
}
signed main()
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
	a[1]=10;
	for(int i=2;i<=10;i++) a[i]=a[i-1]*10;
	int T=1;
	cin>>T;
	while(T--) solve();
}
