#include <bits/stdc++.h>
using namespace std;
int a[6];
int fx()
{
	int cnt=0;
	for(int i=3;i<=5;i++) cnt+=(a[i-2]+a[i-1])==a[i];
	return cnt;
}
void solve()
{
	cin>>a[1]>>a[2]>>a[4]>>a[5];
	a[3]=a[1]+a[2];
	int ans=0;
	ans=max(ans,fx());
	a[3]=a[4]-a[2];
	ans=max(ans,fx());
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
