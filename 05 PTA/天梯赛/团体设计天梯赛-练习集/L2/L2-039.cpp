#include <bits/stdc++.h>
using namespace std;


set<int>g[10010];
vector<int>ans;
void dfs(int u,int fa,vector<int>p)
{
	if(p.size()>ans.size()) ans=p;
	for(auto v:g[u])
	{
		if(v==fa) continue;
		p.push_back(v);
		dfs(v,u,p);
		p.pop_back();
	}
}
typedef struct node
{
	vector<int>a;
	int cnt;
}node;
bool cmp(node a1,node a2)
{
	if(a1.cnt==a2.cnt) return a1.a<a2.a;
	return a1.cnt>a2.cnt;
}
void solve()
{
	int n,m,x;
	cin>>n>>m;
	map<vector<int>,int>mp;
	while(n--)
	{
		vector<int>a;
		for(int i=0;i<m;i++)
		{
			cin>>x;
			a.push_back(x);
		}
		mp[a]++;
	}
	vector<node>a;
	
	for(auto i:mp) a.push_back({i.first,i.second});

	sort(a.begin(),a.end(),cmp);
	
	cout<<a.size()<<"\n";
	for(auto i:a)
	{
		cout<<i.cnt;
		for(auto j:i.a) cout<<" "<<j;
		cout<<"\n";
	}
} 

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

