#include <bits/stdc++.h>
using namespace std;
int n,k,a[110];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	cin>>k;
	int ans=0;
	for(int i=1;i<=n;i++) ans+=a[i]>=k;
	cout<<ans<<"\n";
} 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
