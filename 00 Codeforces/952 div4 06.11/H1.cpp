#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int n,m,ans=0;
	cin>>n>>m;
	vector<vector<int>>a(n+2,vector<int>(m+2,0));
	vector<vector<int>>s(n+2,vector<int>(m+2,0));
	vector<vector<int>>x(n+2,vector<int>(m+2,0));
	vector<vector<int>>z(n+2,vector<int>(m+2,0));
	vector<vector<int>>y(n+2,vector<int>(m+2,0));
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		char ch;
		cin>>ch;
		if(ch=='#') a[i][j]=1;
	}
	
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		if(a[i][j])
		{
			s[i][j]=s[i-1][j]+1;
			z[i][j]=z[i][j-1]+1;
		}
		
	}
	
	for(int j=m;j>=1;j--)
	for(int i=n;i>=1;i--)
	{
		if(a[i][j])
		{
			x[i][j]=x[i+1][j]+1;
			y[i][j]=y[i][j+1]+1;
		}
	}
	
	
	
	for(int i=1;i<=n;i++,cout<<"\n") for(int j=1;j<=m;j++) cout<<y[i][j]<<" ";
	
	
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) s[i][0]+=s[i][j],x[i][0]+=x[i][j];
	
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) z[0][j]+=z[i][j],y[0][j]+=y[i][j];
	
	for(int i=1;i<=n;i++) 
	{
		cout<<n+s[i-1][0]+x[i+1][0]<<"\n";
		ans=max(ans,n+s[i-1][0]+x[i+1][0]);
	}
	
	for(int j=1;j<=m;j++) ans=max(ans,m+z[0][j-1]+y[0][j+1]);
	cout<<ans<<"\n";

}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
