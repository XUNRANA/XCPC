#include <bits/stdc++.h>
using namespace std;
#define N 1000010
int is[N];
int in[N];
int h[N];
vector<int>g[N];
int sz[N];
int tmp[N];
void solve()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>is[i];
	for(int i=1;i<=n;i++)
	{
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
		in[v]++;
		in[u]++;
	}
	for(int i=1;i<=n;i++) sz[i]=is[i];
	queue<int>q;
	for(int i=1;i<=n;i++) 
	if(in[i]==1) q.push(i);
	int ans=0;
	while(!q.empty())
	{
		int u=q.front();
		ans=max(ans,sz[u]);
		q.pop();
		for(auto v:g[u])
		{
			if(in[v]>1)
			{	
				ans=max(ans,sz[v]+sz[u]);
				sz[v]=max(sz[u]+is[v],sz[v]);
				in[v]--;
				if(in[v]==1) q.push(v);
			}
		}
	}
	
	int cnt=0;
	for(int i=1;i<=n;i++) 
	if(in[i]==2) h[i]=1,cnt++;//环上的点  
	else h[i]=0;
	
	vector<int>p,s;//环上的点 
	p.push_back(0);
	s.push_back(0);
	for(int i=1;i<=n;i++)
	if(h[i]==1)
	{
		p.push_back(i);
		int pre=0;
		while(p.size()!=cnt+1)
		{
			for(auto v:g[i]) 
			if(h[v]&&v!=pre) 
			{
				p.push_back(v);
				pre=i;
				i=v;
				break;				
			} 
		}
		break;
	}
	
	int nn=p.size()-1;
 
 	int sum=0;
	for(int i=1;i<=nn;i++) 
	{
		sum+=is[p[i]];
		p.push_back(p[i]);
	}
	
	for(int i=1;i<=nn;i++) 
	{
		int mx1=0,mx2=0;
		for(auto v:g[p[i]])
		{
			if(h[v]) continue;
			if(sz[v]>mx1) 
			{
				mx2=mx1;
				mx1=sz[v];
			}
			else if(sz[v]>mx2) mx2=sz[v];
		}
		ans=max(ans,mx1+mx2+sum);
	}

	multiset<int>st;
	st.insert(0);

	
	for(int i=1;i<p.size();i++)
	{
		int u=p[i];
		
		s.push_back(s.back()+is[u]);
		
		if(i>=nn) st.erase(st.find(tmp[i-nn]));
		
		ans=max(ans,sz[u]+s[i]-is[u]+*st.rbegin());	
		
		tmp[i]=sz[u]-s[i-1]-is[u];
		
		st.insert(tmp[i]);
	}
	cout<<ans<<"\n";
}
/*
4
1 0 1 1
1 2
2 3
3 4
4 1
*/
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
} 
