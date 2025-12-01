#include <bits/stdc++.h>
using namespace std;
#define int long long 
int n,k;
char a[1010][1010];
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin>>a[i][j];
	for(int i=1;i<=n;i+=k) 
	{
		for(int j=1;j<=n;j+=k) cout<<a[i][j];
		cout<<"\n";
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
