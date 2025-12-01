#include <bits/stdc++.h>
using namespace std;

int n,m;
string s;
char a[110][110];
char b[110][110];
// can[i][x][y]: 从 (x,y) 匹配到 s[i] 起，能否完成剩余匹配
bool can_[21][100][100];

int f;
int dx[]={-1,-1,-1,0,0,1,1,1};
int dy[]={-1,0,1,-1,1,-1,0,1};
void dfs(int i,int j,int idx)
{
    if(f) return ;
	if(idx==s.size())
	{
		for(int i=1;i<=n;i++,cout<<"\n")
		{
			for(int j=1;j<=m;j++) 
            if(a[i][j]=='?') cout<<b[i][j];
			else cout<<".";
		}
        f=1;
		return ;
	}

	for(int k=0;k<8;k++)
	{
		int nx=i+dx[k];
		int ny=j+dy[k];
		if(nx<1||nx>n||ny<1||ny>m) continue;
        if(a[nx][ny]==s[idx]&&can_[idx][nx][ny])
		{
			a[nx][ny]='?';
			dfs(nx,ny,idx+1);
            if(f) return ; 
			a[nx][ny]=s[idx];
		}
	}
}

void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
			b[i][j]=a[i][j];
		}
	} 
	
	cin>>s;



    int L=s.size();

    memset(can_, 0, sizeof(can_));
    // 最后一层
    for(int x=1;x<=n;x++)
    {
        for(int y=1;y<=m;y++)
        {
            if(a[x][y] ==s[L-1]) can_[L-1][x][y] = true;
        }
    }
    // 反向递推
    for(int i=L-2;i>=0;i--)
    {
        for(int x=1;x<=n;x++)
        {
            for(int y=1;y<=m;y++)
            {
                if(a[x][y]!=s[i]) continue;
                for(int d=0;d<8;d++)
                {
                    int nx=x+dx[d];
                    int ny=y+dy[d];
                    if(nx<1||nx>n||ny<1||ny>m) continue;
                    if(can_[i+1][nx][ny])
                    {
                        can_[i][x][y]=true;
                        break;
                    }
                }
            }
        }
    }


	for(int i=1;i<=n;i++) 
    for(int j=1;j<=m;j++) 
    if(a[i][j]==s[0]) 
	{
		a[i][j]='?';
		dfs(i,j,1);
		a[i][j]=s[0];
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
