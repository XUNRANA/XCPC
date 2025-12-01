#include <bits/stdc++.h>
using namespace std;
struct node
{
	int x,y;
}p[25010];
bool cmp(node p1,node p2)
{
	if(p1.x==p2.x) return p1.y<p2.y;
	return p1.x<p2.x;
}
void solve()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>p[i].x>>p[i].y;
	sort(p+1,p+1+n,cmp);
	map<pair<int,int>,vector<int> >cnt;
	for(int i=2;i<=n;i++)
	{
		int dx=p[i].x-p[1].x;
		int dy=p[i].y-p[1].y;
		int t=__gcd(abs(dx),abs(dy));
		dx/=t;
		dy/=t;
		cnt[{dx,dy}].push_back(i);
	}
	if(cnt.size()==1)
	{
		cout<<"NO\n";
		return ;
	}
	
	if(cnt.size()>=4)
	{
		cout<<"YES\n";
		vector<pair<int,int> >v;
		v.push_back({p[1].x,p[1].y});
		for(auto i:cnt)
		{
			if(v.size()<5)
			{
				v.push_back({p[i.second[0]].x,p[i.second[0]].y});
			}
			else break;
		}
		for(auto i:v) cout<<i.first<<" "<<i.second<<"\n";
		return ;
	}
	else
	{
		vector<pair<int,int> >v;
		for(auto i:cnt)
		{
			if(i.second.size()>=4)
			{
				for(int j=0;j<4;j++)
				v.push_back({p[i.second[j]].x,p[i.second[j]].y});
				for(auto j:cnt)
				{
					if(j.first==i.first) continue;
					cout<<"YES\n";
					cout<<p[j.second[0]].x<<" "<<p[j.second[0]].y<<"\n";
					for(auto i:v) cout<<i.first<<" "<<i.second<<"\n";
					return ;
				}
			}
		}
		
		for(int i=1;i<=n;i++)
		{
			map<pair<int,int>,int>mp;
			for(int j=1;j<=n;j++)
			{
				if(j==i) continue;
				int dx=p[j].x-p[i].x;
				int dy=p[j].y-p[i].y;
				int t=__gcd(abs(dx),abs(dy));
				dx/=t;
				dy/=t;
				mp[{dx,dy}]=j;
			}
			if(mp.size()>=4)
			{
				cout<<"YES\n";
				vector<pair<int,int> >v;
				v.push_back({p[i].x,p[i].y});
				for(auto i:mp)
				{
					if(v.size()<5)
					{
						v.push_back({p[i.second].x,p[i.second].y});
					}
				}
				for(auto i:v) cout<<i.first<<" "<<i.second<<"\n";
				return ;
			}
		}
		cout<<"NO\n";	
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
