#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int n,m;
	cin>>n>>m;
	vector<vector<int>>a(n+1,vector<int>(m+1));
	vector<vector<int>>b(n+1,vector<int>(m+1));
	vector<vector<int>>id(n+1,vector<int>(m+1));
	
	int cnt=1;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) 
	{
		char ch;
		cin>>ch;
		if(ch=='r') a[i][j]=1;
		else if(ch=='l') a[i][j]=2;
		else if(ch=='u') a[i][j]=3;
		else a[i][j]=4;
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) id[i][j]=cnt++;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>b[i][j];
	
	vector<int>in(n*m+1,0);
	vector<int>g(n*m+1,0);
	
	for(int i=1;i<=n;i++) 
	for(int j=1;j<=m;j++) 
	{
		int ni=i,nj=j;
		if(a[i][j]==1) nj+=b[i][j];
		else if(a[i][j]==2) nj-=b[i][j];
		else if(a[i][j]==3) ni-=b[i][j];
		else ni+=b[i][j];
		 
		if(ni<1||ni>n||nj<1||nj>m) 
		{
			g[id[i][j]]=-1;
			continue;
		}
		
		g[id[i][j]]=id[ni][nj];
		in[id[ni][nj]]++;
	}
	
	vector<int>vt(n*m+1,0);
	int f=0;
	for(int i=1;i<=n*m;i++)//???????ÊýµãµÄ·¶Î§ÄØ? 
	{
		if(!in[i])
		{
			int u=i;
			vector<int>v;
			while(u!=-1&&!vt[u])
			{
				vt[u]=1;
				v.push_back(u);
				u=g[u];
			}
			if(v.size()==n*m)
			{
				cout<<"Yes\n";
				return ;
			}
			f=1;
			break;
		}
	}
	
	if(!f)
	{
		int u=1;
		vector<int>v;
		while(u!=-1&&!vt[u])
		{
			vt[u]=1;
			v.push_back(u);
			u=g[u];
		}
		if(v.size()==n*m)
		{
			cout<<"Yes\n";
			return ;
		}
	}
	cout<<"No\n";
	
	
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
