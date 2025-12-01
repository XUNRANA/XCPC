#include <bits/stdc++.h>
using namespace std;
int tr[1000010];
int lowbit(int x)
{
	return x&-x;
}
void add(int i,int x)
{
	while(i<=1000000)
	{
		tr[i]+=x;
		i+=lowbit(i);
	}
}
int query(int i)
{
	int res=1;
	while(i)
	{
		res+=tr[i];
		i-=lowbit(i);
	}
	return res;
}


struct node
{
	int u,v,w;
}g[1000010];
bool cmp(node g1,node g2)
{
	return g1.w<g2.w;
}

struct node1
{
	int k,d,i;
}q[1000010];
bool cmpq(node1 q1,node1 q2)
{
	return q1.k<q2.k;
}
int cnt[1000010];
int ans[1000010];
void solve()
{
	int n,m,nq;
	cin>>n>>m>>nq;
	
	for(int i=1;i<=m;i++) cin>>g[i].u>>g[i].v>>g[i].w;
	
	sort(g+1,g+1+m,cmp);
	
	for(int i=1;i<=nq;i++)
	{
		cin>>q[i].d>>q[i].k;
		q[i].i=i;
	}
	sort(q+1,q+1+nq,cmpq);
	
//	for(int i=1;i<=m;i++) cout<<g[i].u<<" "<<g[i].v<<" "<<g[i].w<<"\n";
//	for(int i=1;i<=nq;i++) cout<<q[i].d<<" "<<q[i].k<<" "<<q[i].i<<"\n";
	for(int i=1,j=1;i<=nq;i++)
	{
		while(j<=m&&g[j].w<=q[i].k)
		{
			if(cnt[g[j].u]) add(cnt[g[j].u],-1);
			cnt[g[j].u]++;
			add(cnt[g[j].u],1);	
			if(cnt[g[j].v]) add(cnt[g[j].v],-1);
			cnt[g[j].v]++;
			add(cnt[g[j].v],1);
			j++;
		}
		ans[q[i].i]=n-(query(n)-query(q[i].d));
	}
	for(int i=1;i<=nq;i++) cout<<ans[i]<<"\n";
}
/*
4 3 2
1 2 3
1 3 5
2 3 4
1 4
1 5
*/
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}

