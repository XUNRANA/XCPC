#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 100010
int n,m;
int a[N],x[N],t[N],o[N];
vector<int>g[N];
void solve()
{
	cin>>n>>m;
	
	for(int i=1;i<=n;i++) cin>>a[i],o[i]=a[i],g[i].clear();
	
	for(int i=1;i<=m;i++) 
	{
		cin>>x[i]>>t[i];
		g[t[i]].push_back(i);//g[id]表示可以充电的位置 
	}
	
	int s=0;//紧急情况下用电，不可充的电 
	for(int i=1;i<=n;i++) if(!g[i].size()) s+=a[i],a[i]=0;
	
	priority_queue<int,vector<int>,greater<int>>q;
	
	for(int i=1;i<=n;i++) if(g[i].size()) q.push(g[i][0]);//第一次充电位置插入 
	
	for(int i=1;i<=m;i++)
	{
		int d=x[i]-x[i-1];

		while(d>0&&!q.empty())//用电顺序 
		{
			int u=q.top();
			q.pop();
			if(u<i) continue;//不可用的电 
			int id=t[u];
			int t=min(a[id],d);
			d-=t;
			a[id]-=t; 
			if(a[id]>0) q.push(u);
		}
		
	
		
		if(d>0)//用紧急的电 
		{
			int t=min(d,s);
			s-=t;
			d-=t;
			if(d>0)
			{
				cout<<x[i]-d<<"\n";
				return ;
			}
		}
		
		a[t[i]]=o[t[i]];//充电 
		
		auto j=upper_bound(g[t[i]].begin(),g[t[i]].end(),i); 
		
		if(j!=g[t[i]].end()) q.push(*j);//下一次用电插入 
		else s+=a[t[i]],a[t[i]]=0;//如果之后不可充电，该充电桩变成紧急用电 
	}
	int ans=s+x[m];
	for(int i=1;i<=n;i++) ans+=a[i];
	cout<<ans<<"\n";
}


signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
