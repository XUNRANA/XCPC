#include <bits/stdc++.h>
using namespace std;
#define int long long
int c1,c2,r1,r2;
int dc1,dc2,dr1,dr2;
int r,c,d1,d2;
//北 南 西 东
bool ck(int x1,int y1,int x2,int y2,int x,int y)
{
	if(x==x2||x==y2) return 0;
	if(y==x1||y==y1) return 0;
	return 1;
}
void solve()
{
	//北 南 西 东
	cin>>c1>>c2>>r1>>r2;
	cin>>dc1>>dc2>>dr1>>dr2;
	cin>>r>>c>>d1>>d2;   
	
	for(int i=1;i<=5;i++)
	{
		for(int j=1;j<=5;j++)
		{
			for(int i1=1;i1<=5;i1++)
			{
				for(int j1=1;j1<=5;j1++)
				{
					if(abs(i-i1)+abs(j-j1)==d1&&ck(c1,c2,r1-dr1,r2+dr2,i,j)&&abs(r-i1)+abs(c-j1)==d2&&ck(c1+dc1,c2-dc2,r1-dr1,r2+dr2,i1,j1))
					{
						cout<<i<<" "<<j<<" "<<i1<<" "<<j1<<"\n";
					}
				}
			}
		}
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
