#include <bits/stdc++.h>
using namespace std;
int n,m,cntb,cntw;
char a[1010][1010];
vector<string>t=
{
	"######",
	"##..##",
	"#....#",
	"#....#",
	"##..##",
	"######",
};
bool ck(int x,int y)
{
	if(x<1||y<1) return 0;
	for(int i=0;i<6;i++)
	{
		for(int j=0;j<6;j++)
		{
			int nx=x+i;
			int ny=y+i;
			if(nx>n||ny>m||a[x+i][y+j]!=t[i][j]) return 0;
		}
	}
	return 1;
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>a[i][j];
	cntb=0;
	cntw=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]=='#') cntb++;
			else cntw+=ck(i-1,j-2);
		}
	}
	int x=(cntw*100-cntb)/54;
	cout<<x<<" "<<cntw-2*x<<"\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
} 
