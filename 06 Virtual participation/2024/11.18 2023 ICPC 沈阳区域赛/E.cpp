#include <bits/stdc++.h>
using namespace std;
int x,y,p,q;
int f[110][110][2];
#define INF 1000000000
void solve()
{
	cin>>x>>y>>p>>q;
	for(int i=0;i<=x;i++)
	{
		for(int j=0;j<=y;j++)
		{
			for(int z=0;z<2;z++)
			{
				f[i][j][z]=INF;
			}
		}
	}
	f[x][y][0]=0;
	queue<array<int,3>>Q;
	Q.push({x,y,0});
	while(!Q.empty())
	{
		auto state=Q.front();
		Q.pop();
		int s=state[0];
		int w=state[1];
		int os=x-s;
		int ow=y-w;
		int side=state[2];
		
		for(int i=0;i<=min(s,p);i++)
		{
			for(int j=0;j+i<=p&&j<=w;j++)
			{
				int ss=s-i;
				int sw=w-j;
				if(sw>ss+q&&ss) continue;
				
				if(f[os+i][ow+j][side^1]>f[s][w][side]+1)
				{
					f[os+i][ow+j][side^1]=f[s][w][side]+1;
					Q.push({os+i,ow+j,side^1});
				}
			}
		}
	}
	int ans=INF;
	for(int i=0;i<=y;i++) ans=min(ans,f[x][i][1]);
	if(ans==INF) cout<<"-1\n";
	else cout<<ans<<"\n";
	
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
