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
void solve()
{
	int n,k,x;
	cin>>n;
	vector<int>is(n,0);
	for(int i=0;i<n;i++)
	{
		cin>>k;
		while(k--)
		{
			cin>>x;
			g[i].insert(x);
			is[x]=1;
		}
	}
	
	for(int i=0;i<n;i++)
	if(!is[i]) 
	{
		vector<int>p;
		p.push_back(i);
		dfs(i,-1,p);
	}
	cout<<ans.size()<<"\n";
	int f=0;
	for(auto i:ans)
    {
        if(f) cout<<" ";
        cout<<i;
        f=1;
    }
	cout<<"\n";

} 

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

