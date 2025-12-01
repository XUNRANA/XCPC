#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k,ans,p,l;
#define P 998244353
int a[10000001];
void pre()
{
	a[0]=a[1]=1;
	//for(int i=2;i<=10000000;i++) a[i]=a[i-1]*i%P;
}
void solve()
{
	cin>>n>>k;
	ans=0;
	/*
 	for(int x=k+1;x<=n-1;x++)
	{
		l=x-k+1;//区间长度 
		p=n-x;//区间个数 
		ans=(ans+2*p%P*a[l-2]%P*a[n-l+1]%P)%P;
	}*/
	cout<<ans<<"\n";
}
signed main()
{
	pre();
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
}
