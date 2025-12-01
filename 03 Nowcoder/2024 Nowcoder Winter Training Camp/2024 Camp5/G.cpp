#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[1000010];
int is(int x)
{
	for(int i=2;i*i<=x;i++) if(x%i==0) return 0;
	return 1;
}
void fx(int n)
{
	for(int i=1;i<=n;i++) 
	if(is(i+n))
	{
		int t=n;
		for(int j=i;j<=n;j++) a[j]=t--;	
		if(t>0) fx(t);
		break;
	}
}
void solve()
{
	cin>>n;
	fx(n);
	for(int i=1;i<=n;i++) cout<<a[i]<<" ";
	cout<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
