#include <bits/stdc++.h>
using namespace std;
int n,m,ans[110][110];
int ck(int x,int y)
{
	if(x>n+1||y>m+1) return 1;
	return 0;
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n+1;i++)
	{
		for(int j=1;j<=m+1;j++)
		{
			for(int r=1;r;r++)
			{
				if(ck(i+r,j+r)==1) break;
				if(r>=2)
				{				
					for(int j1=j;j1<=j+r;j1++) ans[i][j1]++,ans[i+r][j1]++;
					for(int i1=i;i1<=i+r;i1++) ans[i1][j]++,ans[i1][j+r]++;
					ans[i][j]--;
					ans[i+r][j]--;
					ans[i][j+r]--;
					ans[i+r][j+r]--;
					
				}
				else
				{
					ans[i][j]++;
					ans[i+1][j]++;
					ans[i][j+1]++;
					ans[i+1][j+1]++;
				}
			}
		}
	}
	for(int i=1;i<=n+1;i++,cout<<"\n") for(int j=1;j<=m+1;j++) cout<<ans[i][j]<<" ";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
