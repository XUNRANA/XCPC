#include <bits/stdc++.h>
using namespace std;
int n,now,a[110];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=2;i<=n;i++) if(a[i]<=a[i-1]) a[i]=(a[i-1]/a[i]+1)*a[i];
	cout<<a[n]<<"\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
}
