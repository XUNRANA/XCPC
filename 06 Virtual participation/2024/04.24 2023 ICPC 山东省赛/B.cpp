#include <bits/stdc++.h>
using namespace std;
#define int long long
int g,a,b,n,m,k,ans;
void solve()
{
	map<int,int>h;
	map<int,vector<pair<int,int>>>re;
	map<int,priority_queue< pair<int,int>,vector<pair<int,int> > ,greater<pair<int,int>> >>ne;
	cin>>g;
	while(g--)
	{
		cin>>a>>b;
		h[a]+=b;
	}
	cin>>n;
	vector<int>in(n+1,0);
	queue<int>q;
	for(int i=1;i<=n;i++)
	{
		cin>>m;
		while(m--)
		{
			cin>>a>>b;
			if(h[a]>=b) continue;
			ne[a].push({b,i});//Dии?ио 
			in[i]++;//?иии║y++ 
		}
		cin>>k;
		while(k--)
		{
			cin>>a>>b;
			re[i].push_back({a,b});//?б└ид? 
		}
		if(in[i]==0) q.push(i);
	}
	ans=q.size();
	while(q.size())
	{
		int i=q.front();
		q.pop();
		for(auto j:re[i]) 
		{
			a=j.first;
			b=j.second;
			h[a]+=b;
			while(!ne[a].empty())
			{
				if(h[a]>=ne[a].top().first)
				{
					in[ne[a].top().second]--;
					if(in[ne[a].top().second]==0) 
					{
						q.push(ne[a].top().second);
						ans++;
					}
					ne[a].pop();
				}
				else break;
			}
		}
	}
	cout<<ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
} 
