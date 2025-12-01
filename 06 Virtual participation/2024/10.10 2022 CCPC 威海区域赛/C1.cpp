#include <bits/stdc++.h>
using namespace std;
struct node
{
	int x,y;
}p[25010];
vector<int>path;
int ck()
{
	for(auto i:path)
	{
		map<pair<int,int>,int>mp;
		for(auto j:path)
		{
			if(j==i) continue;
			int dx=p[j].x-p[i].x;
			int dy=p[j].y-p[i].y;
			int t=__gcd(abs(dx),abs(dy));
			dx/=t;
			dy/=t;
			mp[{dx,dy}]=1;
		}	
		if(mp.size()==4) return i;
	}
	return 0;
}
void solve()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>p[i].x>>p[i].y;

	if(n<5)
	{
		cout<<"NO\n";
		return ;
	}
	path.clear();
	path.push_back(1);
	path.push_back(2);
	path.push_back(3);
	path.push_back(4);
	for(int i=5;i<=n;i++)
	{
		path.push_back(i);
		int c=ck();
		if(c)
		{
			cout<<"YES\n";
			cout<<p[c].x<<" "<<p[c].y<<"\n";
			for(auto j:path)
			{
				if(j==c) continue;
				cout<<p[j].x<<" "<<p[j].y<<"\n";
			}
			return ;
		}
		path.pop_back();
	}
	cout<<"NO\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
