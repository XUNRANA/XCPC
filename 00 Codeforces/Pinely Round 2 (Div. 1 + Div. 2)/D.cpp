#include <bits/stdc++.h>
using namespace std;
char a[510][510];
int ans[510][510];
void solve()
{
	int n,m;
	cin>>n>>m;
	vector<int>c(m+2,0);
	vector<int>r(n+2,0);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
			if(a[i][j]=='L') c[j]++;
			else if(a[i][j]=='U') r[i]++;
		}
	}
	int f=0;
	for(int i=1;i<=n;i++) if(r[i]&1) f=1;
	for(int i=1;i<=m;i++) if(c[i]&1) f=1;
	if(f)
	{
		cout<<"-1\n";
		return ;
	}

	for(int i=1;i<=n;i++)
	{
		int l=1;
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]=='U')
			{
				if(!l) 
				{
					ans[i][j]=1;
					ans[i+1][j]=2;
				}
				else 
				{
					ans[i][j]=2;
					ans[i+1][j]=1;
				}
				l^=1;
			}
		}
	}

	for(int j=1;j<=m;j++)
	{
		int l=1;
		for(int i=1;i<=n;i++)
		{
			if(a[i][j]=='L')
			{
				if(!l) 
				{
					ans[i][j]=1;
					ans[i][j+1]=2;
				}
				else 
				{
					ans[i][j]=2;
					ans[i][j+1]=1;
				}
				l^=1;
			}
		}
	}

	for(int i=1;i<=n;i++,cout<<"\n")
	for(int j=1;j<=m;j++)
	if(a[i][j]!='.')
	{
		if(ans[i][j]==1) cout<<"B";
		else cout<<"W";
	}
	else cout<<".";
} 

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}


