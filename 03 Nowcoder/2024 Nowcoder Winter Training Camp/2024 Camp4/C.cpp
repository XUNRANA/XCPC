#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,x,y,p,q,op[110],z[110];
char a[110][110];
void solve()
{
	cin>>n>>m>>x>>y;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>a[i][j];
	cin>>p>>q;
	for(int i=1;i<=q;i++) cin>>op[i]>>z[i];
	while(p--)
	{
		for(int i=1;i<=q;i++)
		{
			if(op[i]==1)
			{
				int h=z[i];
				char t=a[h][m];
				for(int i=m;i>=2;i--) a[h][i]=a[h][i-1];
				a[h][1]=t;
			}
			else
			{
				int l=z[i];
				char t=a[n][l];
				for(int j=n;j>=2;j--) a[j][l]=a[j-1][l];
				a[1][l]=t;
			}
		}
	}
	cout<<a[x][y];
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
