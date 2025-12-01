#include <bits/stdc++.h>
using namespace std;
int n,a[110];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	cout<<(2*abs(a[n]+a[n-1]-a[1]-a[2]))<<"\n"; 
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
}
