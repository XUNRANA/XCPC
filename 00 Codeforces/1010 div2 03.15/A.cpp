#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	int n,m;
	cin>>n>>m;
	vector<int>r(n+1,0);
	vector<int>c(m+1,0);
	for(int i=1;i<=n;i++) 
	for(int j=1;j<=m;j++)
	{
		char ch;
		cin>>ch;
		r[i]^=ch-'0';
		c[j]^=ch-'0';
	}
	int cr=0,cc=0;
	for(int i=1;i<=n;i++) if(r[i]!=0) cr++;
	for(int i=1;i<=m;i++) if(c[i]!=0) cc++;
	cout<<max(cc,cr)<<"\n";
}  

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}

