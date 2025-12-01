#include <bits/stdc++.h>
using namespace std;
#define P 1000000007
long long n,k,a[100010],ans,s;
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	ans=a[n];
	for(int i=n-1;i>=n-k;i--) ans=ans*a[i]%P;
	s=k;
	for(int i=n-k-1;i>=1;i--) s+=a[i];
	cout<<(ans+s)%P<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
