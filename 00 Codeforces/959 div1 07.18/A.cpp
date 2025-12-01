#include <bits/stdc++.h>
using namespace std;
int n,m,a[100][100];
void solve()
{
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
		}
	}
	if(n*m==1)
	{
		cout<<"-1\n";
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]==n*m) cout<<"1 ";
			else cout<<a[i][j]+1<<" ";
		}
		cout<<"\n";
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
