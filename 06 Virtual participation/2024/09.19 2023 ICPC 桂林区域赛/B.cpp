#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 200010
int n,m,a[300010],b[300010];
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i]; 
	for(int i=1;i<=m;i++) cin>>b[i];
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
