#include <bits/stdc++.h>
using namespace std;
int a[1010][1010];

int d[1010][1010][3];
int vt[1010][1010][3];

int dx[]={-2,2,0,0};
int dy[]={0,0,-2,2};
int n,m,sx,sy;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			char ch;
			cin>>ch;
			a[i][j]=ch-'0';
			if(a[i][j]==3) 
			{
				sx=i;
				sy=j;
				a[i][j]=0;
			}
		}
	}
	
	priority_queue<array<int,4>,vector<array<int,4>>,greater<array<int,4>>>q;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) for(int k=0;k<3;k++) d[i][j][k]=1e9,vt[i][j][k]=0;
		
	//0 ÊúÁ¢
	//1 ºáÎÔ y y+1
	//2 ÊúÎÔ x x+1 
	//dis st x y
	q.push({0,0,sx,sy});
	d[sx][sy][0]=0;
	while(!q.empty())
	{
		int dis=q.top()[0];
		int st=q.top()[1];
		int x=q.top()[2];
		int y=q.top()[3];
		q.pop();
		if(vt[x][y][st]) continue;
		vt[x][y][st]=1;
		
		if(st==0)
		{
			//x y 0   x-2 y 2
			if(x-2>=1&&a[x-2][y]&&a[x-1][y])
			{
				if(d[x-2][y][2]>dis+1)
				{
					d[x-2][y][2]=dis+1;
					q.push({d[x-2][y][2],2,x-2,y});		
				}
			}
			
			
			//x y 0   x+1 y 2
			if(x+2<=n&&a[x+1][y]&&a[x+2][y])
			{
				if(d[x+1][y][2]>dis+1)
				{
					d[x+1][y][2]=dis+1;
					q.push({d[x+1][y][2],2,x+1,y});	
				}
			}
			
			
			//x y 0  x y-2 1
			if(y-2>=1&&a[x][y-1]&&a[x][y-2])
			{
				if(d[x][y-2][1]>dis+1)
				{
					d[x][y-2][1]=dis+1;
					q.push({d[x][y-2][1],1,x,y-2});	
				}
			}
			
			
			//x y 0  x y+1 1
			if(y+2<=m&&a[x][y+1]&&a[x][y+2])
			{
				if(d[x][y+1][1]>dis+1)
				{
					d[x][y+1][1]=dis+1;
					q.push({d[x][y+1][1],1,x,y+1});	
				}
			}
		}
		else if(st==1)
		{
			// x y 1(x y+1)
			
			//x y 1 x-1 y 1
			if(x-1>=1&&a[x-1][y]&&a[x-1][y+1])
			{
				if(d[x-1][y][1]>dis+1)
				{
					d[x-1][y][1]=dis+1;
					q.push({d[x-1][y][1],1,x-1,y});	
				}
			}
			
			//x y 1 x+1 y 1
			if(x+1<=n&&a[x+1][y]&&a[x+1][y+1])
			{
				if(d[x+1][y][1]>dis+1)
				{
					d[x+1][y][1]=dis+1;
					q.push({d[x+1][y][1],1,x+1,y});	
				}
			}
			
			//x y 1  x y-1 0
			if(y-1>=1&&a[x][y-1]==1)
			{
				if(d[x][y-1][0]>dis+1)
				{
					d[x][y-1][0]=dis+1;
					q.push({d[x][y-1][0],0,x,y-1});
				}
			}
			
			//x y 1  x y+2 0
			if(y+2<=m&&a[x][y+2]==1)
			{
				if(d[x][y+2][0]>dis+1)
				{
					d[x][y+2][0]=dis+1;
					q.push({d[x][y+2][0],0,x,y+2});
				}
			}
		}
		else if(st==2)
		{
			//x y 2 (x+1 y)  x-1 y 0
			if(x-1>=1&&a[x-1][y]==1)
			{
				if(d[x-1][y][0]>dis+1)
				{
					d[x-1][y][0]=dis+1;
					q.push({d[x-1][y][0],0,x-1,y});
				}
			}
			
			//x y 2  x+2 y 0
			if(x+2<=n&&a[x+2][y]==1)
			{
				if(d[x+2][y][0]>dis+1)
				{
					d[x+2][y][0]=dis+1;
					q.push({d[x+2][y][0],0,x+2,y});
				}
			}
			
			//x y 2 x y-1 2
			if(y-1>=1&&a[x][y-1]&&a[x+1][y-1])
			{
				if(d[x][y-1][2]>dis+1)
				{
					d[x][y-1][2]=dis+1;
					q.push({d[x][y-1][2],2,x,y-1});
				}
			}
			
			//x y 2   x y+1 2
			if(y+1<=m&&a[x][y+1]&&a[x+1][y+1])
			{
				if(d[x][y+1][2]>dis+1)
				{
					d[x][y+1][2]=dis+1;
					q.push({d[x][y+1][2],2,x,y+1});
				}
			}
			
		}
	}
	int nq;
	cin>>nq;
	while(nq--)
	{
		int x,y,s;
		cin>>x>>y>>s;
		if(d[x][y][s]==1e9) cout<<"-1\n";
		else cout<<d[x][y][s]<<"\n";
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
