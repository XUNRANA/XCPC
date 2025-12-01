#include <bits/stdc++.h>
using namespace std;
#define M 10010
#define N 210
#define int long long
int h[N],d[N],cur[N],s,t;
int idx=1;
struct edge
{
	int v,c,ne;
}e[M];
void add(int a,int b,int c)
{
	e[++idx]={b,c,h[a]};
	h[a]=idx;
}
bool bfs()//对点分层，找增广路 
{
	memset(d,0,sizeof d);
	queue<int>q;
	q.push(s);
	d[s]=1;
	while(q.size())
	{
		int u=q.front();
		q.pop();
		for(int i=h[u];i;i=e[i].ne)
		{
			int v=e[i].v;
			if(d[v]==0&&e[i].c)
			{
				d[v]=d[u]+1;
				q.push(v);
				if(v==t) return true;
			}
		}
	}
	return false;
}
int dfs(int u,int mf)//多路增广 
{
	if(u==t) return mf;
	int sum=0;
	for(int i=cur[u];i;i=e[i].ne)
	{
		cur[u]=i;//当前弧优化 
		int v=e[i].v;
		if(d[v]==d[u]+1&&e[i].c)
		{
			int f=dfs(v,min(mf,e[i].c));
			e[i].c-=f;
			e[i^1].c+=f;//更新残留网 
			sum+=f;//累加u的流出流量 
			mf-=f;//减少u的剩余流量 
			if(!mf) break;//余量优化 
		}
	}
	if(sum==0) d[u]=0;//残枝优化 
	return sum;
}
int dinic()//累加可行流 
{
	int flow=0;
	while(bfs())
	{
		memcpy(cur,h,sizeof h);
		flow+=dfs(s,1e9);
	}
	return flow;
}
void solve()
{
	int n,m,u,v,w;
	cin>>n>>m>>s>>t;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		add(u,v,w);
		add(v,u,0);
	}
	cout<<dinic()<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}
