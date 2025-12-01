#include <bits/stdc++.h>
using namespace std;
int n,m,l,r,k,f[1000010][30];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>f[i][0];
	for(int i=1;i<=29;i++) for(int j=1;j+(1<<i)-1<=n;j++)
	f[j][i]=max(f[j][i-1],f[j+(1<<(i-1))][i-1]);
	cin>>m;
	while(m--)
	{
		cin>>l>>r;
		k=log2(r-l+1);
		cout<<max(f[l][k],f[r-(1<<k)+1][k])<<"\n";
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
