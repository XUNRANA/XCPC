#include <bits/stdc++.h>
using namespace std;
int n,a[100010],ans;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=2;i<=n-1;i++) ans+=(a[i]>=a[i-1]+a[i+1]);
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
} 
