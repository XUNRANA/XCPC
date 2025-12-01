#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k;
struct node
{
	int x,y;
}p[10010];
bool cmp(node p1,node p2)
{
	if(p1.x==p2.x) return p1.y<p2.y;
	return p1.x<p2.x;
}
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>p[i].x>>p[i].y;
	for(int i=2;i<=n;i++)
	{
		int dx=p[i].x-p[1].x;
		int dy=p[i].y-p[1].y;
		//y=dy/dx *x +b
		// dx*y=dy*x+b*dx
		map<int,vector<int> >mp;
		for(int j=1;j<=n;j++)
		{
			mp[dx*p[j].y-dy*p[j].x].push_back(j);
			if(mp.size()>k) break;
		}
		if(mp.size()==k)
		{
			int f=1;
			for(auto i1:mp)
			{
				if(i1.second.size()==1) 
				{
					f=0;
					break;
				}
			}
			
			if(f) 
			{	
				for(auto i1:mp)
				{
					cout<<i1.second.size()<<" ";
					for(auto i2:i1.second) cout<<i2<<" ";
					cout<<"\n";
				}
				return ;
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
