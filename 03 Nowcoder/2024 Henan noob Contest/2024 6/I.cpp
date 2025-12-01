#include <bits/stdc++.h>
using namespace std;
#define int long long
string s;
int n,m,a[200010];
void solve()
{
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) 
	{
		if(s[i-1]=='P') a[i]=1;
		else a[i]=0;
	}
	for(int i=1;i<=m;i++) if(i&1) a[i]^=1;
	for(int i=m;i>=1;i-=2) cout<<a[i]<<" ";
	if(m&1) for(int i=2;i<m;i+=2) cout<<a[i]<<" ";
	else for(int i=1;i<m;i+=2) cout<<a[i]<<" ";
	for(int i=m+1;i<=n;i++) cout<<a[i]<<" ";
	cout<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
