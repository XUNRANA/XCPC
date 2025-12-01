#include <bits/stdc++.h>
using namespace std;

int a[110][110];
void solve()
{
	int n,m;
	cin>>n>>m;
	for(int j=1;j<=n*m;j++)
	{
		string s;
		cin>>s;
		int x=1,y=1;
		for(auto i:s)
		{
			if(i=='1') y=min(y+1,m);
			else if(i=='2') x=min(x+1,n);
			else if(i=='3') y=max(y-1,1);
			else if(i=='4') x=max(x-1,1);
			else if(!a[x][y]) a[x][y]=j;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(j!=1) cout<<" ";
			cout<<a[i][j];
		}
		cout<<"\n";
	}
	
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}
