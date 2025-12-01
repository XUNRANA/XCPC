#include <bits/stdc++.h>
using namespace std;
int n,m,l,ans,a[110][110],b[110][110];
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>a[i][j],b[i][j]=a[i][j];
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) a[i][j]+=a[i][j-1]+a[i-1][j]-a[i-1][j-1];
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
	if(b[i][j]==1)
	{
		l=1;
		while(i+l-1<=n&&j+l-1<=m&&a[i+l-1][j+l-1]-a[i-1][j+l-1]-a[i+l-1][j-1]+a[i-1][j-1]==l*l) l++;
		ans=max(ans,l-1);
	}
	cout<<ans;
}
