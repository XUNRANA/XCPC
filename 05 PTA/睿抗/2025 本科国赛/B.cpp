#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<array<int,2>>a;
int ans[51][51];
int n,m,q;
bool ck(int x,int y)
{
	for(auto i:a)
	{
		int nx=i[0]+x;
		int ny=i[1]+y;
		if(nx<1||nx>n||ny<1||ny>m||ans[nx][ny]) return 0;
	}
	
	for(auto i:a)
	{
		int nx=i[0]+x;
		int ny=i[1]+y;
		ans[nx][ny]=1;
	}
	
	return 1;

}
void solve()
{

	cin>>n>>m>>q;
	while(q--)
	{
		a.clear();
//		vector<array<int,2>>a;
		int x=-1,y=-1;
		int n1,m1;
		cin>>n1>>m1;
		for(int i=1;i<=n1;i++)
		{
			for(int j=1;j<=m1;j++)
			{
				char ch;
				cin>>ch;
				if(ch=='*')
				{
					if(x==-1)
					{
						x=i;
						y=j;
						a.push_back({0,0});
					}
					else
					{
						a.push_back({i-x,j-y});
					}
				}
			}
		}
		int f=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(ck(i,j))
				{
					cout<<i<<" "<<j<<"\n";
					f=1;
					break;
				}
			}
			if(f) break;
		}
		if(!f) cout<<"-1 -1\n";
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
