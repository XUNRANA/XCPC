#include <bits/stdc++.h>
using namespace std;
int dis[8][8];
void init()
{
	for(int i=1;i<=7;i++)
	{
		for(int j=1;j<=7;j++)
		{
			if(i==j) dis[i][j]=0;
			else dis[i][j]=10;
		}
	}
		
	dis[1][2]=1;
	dis[1][3]=1;
	
	dis[2][1]=1;
	dis[2][4]=1;
	
	dis[3][1]=1;
	dis[3][4]=1;
	
	dis[4][2]=1;
	dis[4][3]=1;
	dis[4][5]=1;
	dis[4][6]=1;
	
	dis[5][4]=1;
	dis[5][7]=1;
	
	dis[6][4]=1;
	dis[6][7]=1;
	
	dis[7][5]=1;
	dis[7][6]=1;
	
	for(int k=1;k<=7;k++)
	{
		for(int u=1;u<=7;u++)
		{
			for(int v=1;v<=7;v++)
			{
				dis[u][v]=min(dis[u][v],dis[u][k]+dis[k][v]);
			}
		}
	}
}
void solve()
{
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	cout<<min(dis[a][c]+dis[b][d],dis[a][d]+dis[b][c])<<"\n";
}


int main()
{
	init();
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
