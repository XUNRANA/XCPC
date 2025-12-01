#include <bits/stdc++.h>
using namespace std;
char g[110][110];
void solve()
{
	int h,w,n;
	cin>>h>>w>>n;
	for(int i=1;i<=h;i++) for(int j=1;j<=w;j++) g[i][j]='.';
	int x=1,y=1,f=1;
	while(n--)
	{
		if(g[x][y]=='.') 
		{
			g[x][y]='#';
			f++;
			if(f==5) f=1;
		}
		else
		{
			g[x][y]='.';
			f--;
			if(f==0) f=4;
		}
		
		if(f==1) 
		{
			x--;
			if(x==0) x=h;
		}
		if(f==2)
		{
			y++;
			if(y==w+1) y=1;
		}
		if(f==3)
		{
			x++;
			if(x==h+1) x=1;
		}
		if(f==4)
		{
			y--;
			if(y==0) y=w;
		}
	}
	for(int i=1;i<=h;i++,cout<<"\n") for(int j=1;j<=w;j++) cout<<g[i][j];
}
int main()
{
	int t;
	t=1;
	//cin>>t;
	while(t--) solve();
}
