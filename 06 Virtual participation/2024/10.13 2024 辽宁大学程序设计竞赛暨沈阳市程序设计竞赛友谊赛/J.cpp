#include <bits/stdc++.h>
using namespace std;
int tot;
int n,m,k;
int a[31][31];
int id[31][31];
int x,y,tx,ty;
int dp[31][31][1<<12];
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
bool ck(int x,int y)
{
	return x>=1&&x<=n&&y>=1&&y<=m;
}
void solve()
{
	cin>>n>>m>>k;
	
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) for(int k1=0;k1<(1<<k);k1++) dp[i][j][k1]=1e9;
	
	tot=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			char ch;
			cin>>ch;
			a[i][j]=ch-'0';
			if(a[i][j]) id[i][j]=tot++;
		}
	}
	
	queue<array<int,4>>q;
	
	cin>>x>>y;
	
	cin>>tx>>ty;
	
	dp[x][y][0]=0;//dp[x][y][k]:点x，y状态为k的时候代价的最小值
	
	q.push({x,y,0,0});//x,y,k,cnt
	
	int ans=1e9;
	while(!q.empty())
	{
		auto u=q.front();
		q.pop();
		if(u[0]==tx&&u[1]==ty&&u[2]==(1<<k)-1)
		{
			ans=min(ans,u[3]);
			continue;
		}
		if(u[3]>dp[u[0]][u[1]][u[2]]) continue;
		for(int i=0;i<4;i++)
		{
			int nx=u[0]+dx[i];
			int ny=u[1]+dy[i];
			int nk=u[2];
			int nc=u[3]+1;
            //越界
			if(!ck(nx,ny)) continue;
			if(a[nx][ny]&&!(u[2]&(1<<id[nx][ny])))
			{//有怪物，还未击败
				int ax=nx;
				int ay=ny;
                //1型怪物
				int tx1=u[0]+dx[i]*2;
				int ty1=u[1]+dy[i]*2;
				//2型怪物
				int tx2=u[0]-dx[i]*2;
				int ty2=u[1]-dy[i]*2;
                //瞬移点为空/怪物已被击败
				if(a[nx][ny]==1&&ck(tx1,ty1)&&(!a[tx1][ty1]||u[2]&(1<<id[tx1][ty1])))
				nx=tx1,ny=ty1;
				else if(a[nx][ny]==2&&ck(tx2,ty2)&&(!a[tx2][ty2]||u[2]&(1<<id[tx2][ty2])))
				nx=tx2,ny=ty2;
				else nx=u[0],ny=u[1];
				nk|=(1<<id[ax][ay]);
				nc--;
			}
			if(nc<dp[nx][ny][nk])
			{
				dp[nx][ny][nk]=nc;
				q.push({nx,ny,nk,nc});
			}
		}
	}
	cout<<ans<<"\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
