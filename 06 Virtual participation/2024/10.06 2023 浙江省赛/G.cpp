#include <bits/stdc++.h>
using namespace std;
#define int long long
struct node
{
	int x,y;
}p[1010];
vector<pair<int,double> >g[1010];
int n,sx,sy,tx,ty,v1,v2;
int vt[1010];
double ans[1010];
double dis(node p1,node p2)
{
	return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
double cal(int u,int v,double d)
{
	if(u>=1&&u<=n)
	{
		if(v2*3>=d) return d/v2;
		else return 3+(d-v2*3)/v1;
	}
	else return d/v1;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>p[i].x>>p[i].y;
	cin>>sx>>sy>>tx>>ty;
	cin>>v1>>v2;
	
	p[n+1]={sx,sy};//Æðµã 
	p[n+2]={tx,ty};//ÖÕµã
	
	g[n+1].push_back({n+2,dis(p[n+1],p[n+2])}); 
	
	for(int i=1;i<=n;i++)
	{
		g[n+1].push_back({i,dis(p[i],p[n+1])});
		g[i].push_back({n+2,dis(p[i],p[n+2])});
	}
	

	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			double d=dis(p[i],p[j]);
			g[i].push_back({j,d});
			g[j].push_back({i,d});
		}
	}	
	
	
	priority_queue<pair<double,int>,vector<pair<double,int>>,greater<pair<double,int>> >q;
	for(int i=1;i<=n+2;i++) vt[i]=0,ans[i]=1e18;
	q.push({0,n+1});
	ans[n+1]=0;
	
	while(!q.empty())
	{
		int u=q.top().second;
		q.pop();
		if(vt[u]) continue;
		vt[u]=1;
		for(auto v1:g[u])
		{
			int v=v1.first;
			double d=v1.second;
			double t=cal(u,v,d);
			if(ans[v]>ans[u]+t)
			{
				ans[v]=ans[u]+t;
				q.push({ans[v],v});
			}
		}
	}
	printf("%.15f\n",ans[n+2]);
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
} 
