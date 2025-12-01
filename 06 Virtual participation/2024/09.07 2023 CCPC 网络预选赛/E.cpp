#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int f[110][110],vt[110][110];
map<pair<int,int>,int>mp;
void dfs(int x,int y,int c)
{
	if(c==n)
	{
		mp[{x,y}]=1;
		return ;
	}
	int nx,ny;
	
	if(s[c]=='L')
	{
		nx=x-1;
		ny=y;
	}
	else if(s[c]=='R')
	{
		nx=x+1;
		ny=y;
	}
	else if(s[c]=='U')
	{
		nx=x;
		ny=y+1;
	}
	else 
	{
		nx=x;
		ny=y-1;
	}
	if(nx==0&&ny==0) dfs(nx,ny,c+1);
	else if(vt[nx+50][ny+50])
	{
		if(f[nx+50][ny+50]==0) dfs(nx,ny,c+1);
		else dfs(x,y,c+1);
	}
	else
	{
		vt[nx+50][ny+50]=1;
		
		f[nx+50][ny+50]=-1;
		dfs(x,y,c+1);
		
		f[nx+50][ny+50]=0;
		dfs(nx,ny,c+1);
		
		vt[nx+50][ny+50]=0;
	}
}
void solve()
{
	cin>>n>>s;
	dfs(0,0,0);
	if(mp.size()==1)
	{
		cout<<"1\n";
		return ;
	}
	cout<<mp.size()<<"\n";
	for(auto i:mp) cout<<i.first.first<<" "<<i.first.second<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();

} 
