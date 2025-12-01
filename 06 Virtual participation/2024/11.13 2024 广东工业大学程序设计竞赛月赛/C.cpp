#include <bits/stdc++.h>
using namespace std;
int n,m,sx,sy,ex,ey;
int vt[100][100];
char a[100][100];
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>a[i][j];
	cin>>sx>>sy>>ex>>ey;
	queue<pair<int,int>>q;
	q.push({sx,sy});
	while(!q.empty())
	{
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		
        if(vt[x][y]) continue;
		
        vt[x][y]=1;
		
        if(a[x][y]=='*') continue;
        
		for(int i=0;i<4;i++)
		{
			int nx=x+dx[i];
			int ny=y+dy[i];
			if(nx<1||nx>n||ny<1||ny>m) continue;
			q.push({nx,ny}); 
		}
	}
    
	if(vt[ex][ey]) cout<<"YES\n";
	else cout<<"NO\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
//     cin>>T;
    while(T--) solve();
}
