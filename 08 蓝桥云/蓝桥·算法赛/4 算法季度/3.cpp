#include <bits/stdc++.h>
using namespace std;
int n,a[100010],b[100010],ans;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) cin>>b[i];
	sort(a+1,a+1+n);
	sort(b+1,b+1+n);
  	ans=2e9;
	for(int i=1;i<=n;i++) ans=min(ans,a[i]+b[n-i+1]);
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}
