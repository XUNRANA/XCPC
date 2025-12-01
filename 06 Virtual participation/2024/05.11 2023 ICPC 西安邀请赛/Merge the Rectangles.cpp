#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[1510][1510],b[1510][1510];
string s;
bool dfs(int x1,int y1,int x2,int y2)
{
	int sum=0;
	for(int i=x1+1;i<x2;i++)
	{
		if(a[i][y2-1]-a[i][y1-1]==y2-y1)
		{
		//	cout<<x1<<" "<<y1<<" "<<i<<" "<<y2<<" "<<i<<" "<<y1<<" "<<x2<<" "<<y2<<"\n";
			return dfs(x1,y1,i,y2)&&dfs(i,y1,x2,y2);
		}
		sum+=a[i][y2-1]-a[i][y1-1];
	}
	for(int j=y1+1;j<y2;j++)
	{
		if(b[x2-1][j]-b[x1-1][j]==x2-x1)
		{
		//	cout<<x1<<" "<<y1<<" "<<x2<<" "<<j<<" "<<x1<<" "<<j<<" "<<x2<<" "<<y2<<"\n";
			return dfs(x1,y1,x2,j)&&dfs(x1,j,x2,y2);
		}
		sum+=b[x2-1][j]-b[x1-1][j];
	}
	if(sum) return false;
	return true;
}
void solve()
{
	cin>>n>>m;
	for(int i=2;i<=n;i++)
	{
		cin>>s;
		for(int j=1;j<=m;j++) a[i][j]=a[i][j-1]+(s[j-1]-'0');
	}
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		for(int j=2;j<=m;j++) b[i][j]=b[i-1][j]+(s[j-2]-'0');
	}
	/*
	for(int i=1;i<=n;i++,cout<<'\n')
	for(int j=1;j<=m;j++) cout<<a[i][j]<<" ";
	cout<<"\n";
	
	for(int i=1;i<=n;i++,cout<<'\n')
	for(int j=1;j<=m;j++) cout<<b[i][j]<<" ";
	cout<<"\n";
	*/
	if(dfs(1,1,n+1,m+1)) cout<<"YES\n";
	else cout<<"NO\n";
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve(); 
}
