#include <bits/stdc++.h>
using namespace std;
int n,m,l,r,k,f[100010][22];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>f[i][0];
	for(int i=1;i<=21;i++) for(int j=1;j+(1<<i)-1<=n;j++)
	f[j][i]=max(f[j][i-1],f[j+(1<<(i-1))][i-1]);
	while(m--)
	{
		cin>>l>>r;
		k=log2(r-l+1);
		cout<<max(f[l][k],f[r-(1<<k)+1][k])<<"\n";
	}
}
