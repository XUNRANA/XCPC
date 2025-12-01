#include <bits/stdc++.h>
using namespace std;
#define int long long
void pre()
{
	
}
int f(int i,int j,int x,int y)
{
	
}
signed main()
{
	cin>>n>>m>>n1>>m1;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>a[i][j];
	pre();
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			x=i+n1;
			y=j+n2;
			if(x>n||y>m) break;
			ans=max(ans,f(i,j,x,y));
		}
	}
}
