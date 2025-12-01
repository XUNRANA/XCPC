#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<pair<int,int>>g[1020];
int vt[1020],dis[1020];
void solve()
{
	int n,m,k,d;
	cin>>n>>m>>k>>d;
	for(int i=1;i<=k;i++)
	{
		string u,v;
		int di;
		cin>>u>>v>>di;
		int a,b;
		if(u[0]=='G'&&v[0]=='G')
		{
			a=stoi(u.substr(1))+n;
			b=stoi(v.substr(1))+n;
		}
		else if(u[0]=='G')
		{
			a=stoi(u.substr(1))+n;
			b=stoi(v);
		}
		else if(v[0]=='G')
		{
			a=stoi(u);
			b=stoi(v.substr(1))+n;
		}
		else
		{
			a=stoi(u);
			b=stoi(v);
		}
		g[a].push_back({b,di});
		g[b].push_back({a,di});
	}

	priority_queue< pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> >q;
	int ansd;
	int ansi;
	int ansmi=0;
	for(int i=n+1;i<=n+m;i++)
	{
		for(int j=1;j<=n+m;j++) vt[j]=0,dis[j]=1e18;
		q.push({0,i});
		dis[i]=0;
		while(!q.empty())
		{
			int u=q.top().second;
			q.pop();
			if(vt[u]) continue;
			vt[u]=1;
			for(auto v1:g[u])
			{
				int v=v1.first;
				int di=v1.second;
				if(dis[u]+di<dis[v])
				{
					dis[v]=dis[u]+di;
					q.push({dis[v],v});
				}
			}
		}
		int s=0;
		int f=0;
		int mi=1e18;
		for(int j=1;j<=n;j++) 
		{
			s+=dis[j];
			mi=min(mi,dis[j]);
			if(dis[j]>d) f=1;
		}
		if(!f&&mi>ansmi)
		{
			ansd=s;
			ansi=i;
			ansmi=mi;
		}
	}
    
	if(ansmi==0) cout<<"No Solution\n";
	else 
	{
		printf("G%d\n%.1f %.1f\n",ansi-n,1.0*ansmi,1.0*ansd/n);
	}
} 

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}
