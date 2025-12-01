#include <bits/stdc++.h>
using namespace std;
int n,t,v[100010],index,cnt;
vector<int>g[100010];
void dfs(int x)
{
	cnt++;
	if(cnt!=n) cout<<x<<" ";
	else cout<<x;
	v[x]=1;
	for(auto i:g[x])
	{
		if(v[i]) continue;
		dfs(i);
	}
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		g[t].push_back(i);
		if(t==0) index=i;
	}
	set<int>s;
	for(int i=1;i<=n;i++) if(g[i].size()) 
	{
		s.insert(g[i].size());
		sort(g[i].begin(),g[i].end());
	}
	if(s.size()==1)
	{
		cout<<*s.begin()<<" yes\n";
		dfs(index);
	}
	else cout<<"no\n";
}
