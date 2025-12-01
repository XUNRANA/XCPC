#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,res,x,y;
char a[1010][1010];
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
	for(int j=1;j<=m;j++) 
	{
		cin>>a[i][j];
		if(a[i][j]!='.'&&a[i][j]!='*')
		{
			x=i;
			y=j;
		}
	}
    
	if(a[x][y]=='A')
	{
		while(y)
		{
			res+=(a[x][y]=='*');
			y--;
		}
	}
	else if(a[x][y]=='W')
	{
		while(x)
		{
			res+=a[x][y]=='*';
			x--;
		}
	}
	else if(a[x][y]=='S')
	{
		while(x<=n)
		{
			res+=a[x][y]=='*';
			x++;
		}
	}
	else
	{
		while(y<=m)
		{
			res+=a[x][y]=='*';
			y++;
		}
	}
	cout<<res<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
