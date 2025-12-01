#include <bits/stdc++.h>
using namespace std;
int n,m,t,ans,f[110][110];
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
	{
		cin>>t;
		if(t&1) f[i][j]=min({f[i-1][j-1],f[i-1][j],f[i][j-1]})+1;
		ans=max(ans,f[i][j]);
	}
	cout<<ans;
}
