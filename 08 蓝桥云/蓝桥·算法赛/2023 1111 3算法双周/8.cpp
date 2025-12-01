#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,s,t,a[100010],dis[200010],vt[200010];
int flag[100000001];
vector<int>g[200010];
vector<int>p;
void init()
{
	for(int i=2;i<=100000000;i++)
	{
		if(!flag[i]) p.push_back(i);
		for(int j=0;j<p.size()&&i*p[j]<=100000000;j++)
		{
			flag[i*p[j]]=1;
			if(i%p[j]==0) break;
		}
	}
	//cout<<p.size()<<"\n"; 6e6
}
void solve()
{
	cin>>n>>s>>t;
	unordered_map<int,int>mp;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		if(mp.count(a[i])) continue;
		if(!flag[a[i]]) mp[a[i]]=a[i]%n+1;//质数   、、数据太弱 
		else
		{
			int t=a[i];
			unordered_map<int,int>cnt;
			for(int i=2;i*i<=t;i++) while(t%i==0) cnt[i]++,t/=i;
			if(t!=1) cnt[t]++;
			int ans=0;
			for(auto i:cnt) ans+=i.first*i.second;
			mp[a[i]]=ans%n+1;
		}
	}
	for(int i=1;i<=n;i++) 
	{
		g[i].push_back(mp[a[i]]);
		g[mp[a[i]]].push_back(i);
		g[mp[a[i]]+n].push_back(i);//虚点，权值位0 
		g[i].push_back(mp[a[i]]+n);//虚点，权值位1 
	}
	for(int i=1;i<=2*n;i++) dis[i]=1e18;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
	dis[s]=0;
	q.push({0,s});
	while(!q.empty())
	{
		int u=q.top().second;
		q.pop();
		if(vt[u]) continue;
		vt[u]=1;
		for(auto v:g[u])
		{
			int w1;
			if(u<=n) w1=1;
			else w1=0;
			if(dis[v]>dis[u]+w1) 
			{
				dis[v]=dis[u]+w1;
				q.push({dis[v],v});
			}
		}
	}
	if(dis[t]==1e18) dis[t]=-1;
	cout<<dis[t]<<"\n";
} 
signed main()
{
	init();
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
} 
