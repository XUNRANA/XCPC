#include <bits/stdc++.h>
using namespace std;
int n,m,a[110][110],x,y;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
			if(a[i][j]==2) 
			{
				x=i;
				y=j;
			}
		}
	}
}
