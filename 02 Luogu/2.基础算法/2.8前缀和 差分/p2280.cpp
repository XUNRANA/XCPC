#include <bits/stdc++.h>
using namespace std;
int n,m,x,y,v,i1,j11,ans,a[5010][5010];
int main()
{
	
	cin>>n>>m;
	while(n--)
	{
		cin>>x>>y>>v;
		a[x][y]+=v;
	}
	for(int i=0;i<=5000;i++) for(int j=0;j<=5000;j++)
	if(!i&&!j) a[i][j]=a[i][j];
	else if(i&&!j) a[i][j]+=a[i-1][j];
	else if(j&&!i) a[i][j]+=a[i][j-1];
	else a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
	for(int i=0;i<=5000;i++) for(int j=0;j<=5000;j++)
	{
		i1=min(5000,i+m-1);
		j11=min(5000,j+m-1);
		if(!i&&!j) ans=max(ans,a[i1][j11]);
		else if(!i&&j) ans=max(ans,a[i1][j11]-a[i1][j-1]);
		else if(i&&!j) ans=max(ans,a[i1][j11]-a[i-1][j11]);
		if(i&&j) ans=max(ans,a[i1][j11]-a[i-1][j11]-a[i1][j-1]+a[i-1][j-1]);
	}
	cout<<ans;
}
