#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,x,y;
int a[1010][1010];
int r[1010];
int c[1010];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
		}
	}
	cin>>x>>y;
	for(int j=1;j<=n;j++) r[j]=a[x][j];
	
	for(int i=1;i<=n;i++) c[i]=a[i][y];
	
	for(int j=1;j<=n;j++) a[x][j]=c[j];
	
	for(int i=1;i<=n;i++) a[i][y]=r[i];
	
	a[x][y]=(r[x]+c[y]+1)/2;
	for(int i=1;i<=n;i++,cout<<"\n") for(int j=1;j<=n;j++) cout<<a[i][j]<<" ";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
