#include <bits/stdc++.h>
using namespace std;
int n,m,a[30][30],b[30][30],ans[30][30];
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin>>a[i][j];
	for(int i=1;i<=m;i++) for(int j=1;j<=m;j++) cin>>b[i][j];
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
		{
			int nx=i+n-1,ny=j+n-1;
			if(nx>m||ny>m) continue;
			for(int i1=1;i1<=n;i1++)
			{
				for(int j1=1;j1<=n;j1++)
				{
					ans[i][j]+=b[i+i1-1][j+j1-1]*a[i1][j1];
				}
			}
		}
	}
	for(int i=1;i<=m-n+1;i++,cout<<"\n") for(int j=1;j<=m-n+1;j++) cout<<ans[i][j]<<" ";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
} 
