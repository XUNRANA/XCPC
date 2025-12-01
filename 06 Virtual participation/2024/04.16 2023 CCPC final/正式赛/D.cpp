#include <bits/stdc++.h>
using namespace std;
int n,m,j,a[100010],b[100010];
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++) cin>>b[i];
	j=1;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==b[j]) j++;
	}
	if(j>m) cout<<"Yes\n";
	else cout<<"No\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
}
