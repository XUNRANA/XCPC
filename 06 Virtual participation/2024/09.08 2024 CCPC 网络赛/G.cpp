#include <bits/stdc++.h>
using namespace std;
#define M 200010
#define N 10010
#define int long long

int h[N],d[N],cur[N],S,T;
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
	q.push(S);
	d[S]=1;
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
				if(v==T) return true;
			}
		}
	}
	return false;
}
int dfs(int u,int mf)//多路增广 
{
	if(u==T) return mf;
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
		flow+=dfs(S,1e9);
	}
	return flow;
}

int n,m,sum,flow,a[1010],v[1010];
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i]>>v[i];
	S=n+m+1;//源点 
	T=S+1;//汇点 
	sum=flow=0;
	for(int i=1;i<=m;i++)//1--n为人。n+1----n+m的点为菜品。 
	{
		int u,v,w;
		cin>>u>>v>>w;
		add(u,n+i,1e9);
		add(n+i,u,0);
		
		add(v,n+i,1e9);
		add(n+i,v,0);
		
		add(n+i,T,w);
		add(T,n+i,0);
		
		flow+=w;
		if(u==1||v==1) sum+=w;
	}
	sum=min(a[1],sum+v[1]);//1号的最大花费 
	
	add(S,1,sum-v[1]);
	add(1,S,0); 
	bool f=1;
	for(int i=2;i<=n;i++)
	{
		a[i]=min(a[i],sum-1);
		if(a[i]<v[i])
		{
			f=0;
			break;
		}
		add(S,i,a[i]-v[i]); 
		add(i,S,0); 
	}
	
	if(!f||dinic()<flow) cout<<"NO\n";
	else cout<<"YES\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}
