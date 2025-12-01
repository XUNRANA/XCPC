#include <bits/stdc++.h>
using namespace std;


void solve()
{
	int n,l;
	cin>>n>>l;
	int x=0,y=0;
	vector<pair<int,int>>a;
	a.push_back({x,y});
	for(int i=1;i<=n;i++)
	{
		int z;
		cin>>z;
		if(i&1) y=z;
		else x=z;
		a.push_back({x,y});
	}
	a.push_back({0,0});
	vector<pair<int,int>>ans;
	ans.push_back({0,0});
	int s=0;
	for(int i=1;i<a.size();i++)
	{
		int px=a[i].first;
		int py=a[i].second;
		x=a[i-1].first;
		y=a[i-1].second;
		if(s+abs(px-x)+abs(py-y)<l) s+=abs(px-x)+abs(py-y);
		else
		{
			if(abs(px-x))
			{
				if(px>=x) 
				{
					ans.push_back({x+l-s,y});
					int cnt=px-x-(l-s);
					if(cnt/l)
					{
						for(int j=1;j<=cnt/l;j++)
						ans.push_back({x+l-s+j*l,y});
					}
				}
				else 
				{
					ans.push_back({x-(l-s),y});
					int cnt=x-px-(l-s);
					if(cnt/l)
					{
						for(int j=1;j<=cnt/l;j++)
						{
							ans.push_back({x-(l-s)-j*l,y});
						}
					}
				}
				s+=abs(px-x)+abs(py-y);
				s%=l;
			}
			else
			{
				if(py>=y) 
				{
					ans.push_back({x,y+l-s});
					int cnt=py-y-(l-s);
					if(cnt/l)
					{
						for(int j=1;j<=cnt/l;j++)
						ans.push_back({x,y+l-s+j*l});
					}
				}
				else 
				{
					ans.push_back({x,y-(l-s)});
					int cnt=y-py-(l-s);
					if(cnt/l)
					{
						for(int j=1;j<=cnt/l;j++)
						{
							ans.push_back({x,y-(l-s)-j*l});
						}
					}
				}
				s+=abs(px-x)+abs(py-y);
				s%=l;
			}	
		}
	}
	if(ans[0]==ans.back()&&ans.size()>1) ans.pop_back();
	for(auto i:ans) cout<<i.first<<" "<<i.second<<"\n";

}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
} 
