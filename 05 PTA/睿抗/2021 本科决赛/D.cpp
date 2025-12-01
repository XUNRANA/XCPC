#include <bits/stdc++.h>
using namespace std;
#define int long long
int d[510][510];
int is[510][510];
int d1[510];
int vt[510];
int pre[510];
int n,m,s,t;
void dij(int s)
{
	for(int i=1;i<=n;i++) d1[i]=1e18,vt[i]=0;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
	d1[s]=0;
	q.push({0,s});
	while(!q.empty())
	{
		int u=q.top().second;
		q.pop();
		if(vt[u]) continue;
		vt[u]=1;
		for(int i=1;i<=n;i++)
		{
			if(!is[u][i]&&d1[i]>d1[u]+d[u][i])
			{
				pre[i]=u;
				d1[i]=d1[u]+d[u][i];
				q.push({d1[i],i});
			}
		}
	}
//	for(int i=1;i<=n;i++) cout<<d1[i]<<" ";
//	cout<<"\n";
}
void solve()
{
	cin>>n>>m>>s>>t;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) d[i][j]=1e18;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		cin>>u>>v>>w;
		d[u][v]=d[v][u]=w;
	}
	dij(s);
	int ans1=1e18;
	int ans2=1e18;
	ans2=min(ans2,d1[t]);
	
	for(int i=1;i<=n;i++)
	{
		dij(s);
		if(d1[i]!=1e18&&i!=s)
		{
			int r1=d1[i];
			vector<int>a;
			for(int j=i;j!=s;j=pre[j]) a.push_back(j);
			a.push_back(s);
			for(int j=1;j<a.size();j++) is[a[j]][a[j-1]]=is[a[j-1]][a[j]]=1;
			dij(i);
			if(d1[s]!=1e18) ans1=min(ans1,r1+d1[s]);
			for(int j=1;j<a.size();j++) is[a[j]][a[j-1]]=is[a[j-1]][a[j]]=0;
		}
	}
	if(ans1==1e18) ans1=-1;
	if(ans2==1e18) ans2=-1;
    cout<<ans1<<" "<<ans2<<"\n";
	if(ans1==-1) cout<<"Lose!\n";
	else if(ans2==-1) cout<<"Win!\n";
	else if(ans1<ans2) cout<<"Win!\n";
	else cout<<"Lose!\n"; 
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
} 
