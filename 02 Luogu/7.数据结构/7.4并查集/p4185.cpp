#include <bits/stdc++.h>
using namespace std;
#define N 100005
struct edge
{
	int u,v,w;
}e[N];
struct query
{
	int k,v,id;
}a[N];
int fa[N],siz[N],ans[N],n,q;
bool cmp1(edge e1,edge e2)
{
	return e1.w>e2.w;
}
bool cmp2(query a1,query a2)
{
	return a1.k>a2.k;
}
void unionn(int x,int y)
{
	if(x==y) return ;
	fa[y]=x;
	siz[x]+=siz[y];
}
int find(int x)
{
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
int main()
{
	cin>>n>>q;
	for(int i=1;i<=n;i++) fa[i]=i,siz[i]=1;
	
	for(int i=1;i<n;i++) cin>>e[i].u>>e[i].v>>e[i].w;
	
	for(int i=1;i<=q;i++)
	{
		cin>>a[i].k>>a[i].v;
		a[i].id=i;
	}
	
	sort(e+1,e+n,cmp1);//按w递减的顺序合并 
	
	sort(a+1,a+q+1,cmp2);//按k递减处理询问 
	
	int cur=1;
	
	for(int i=1;i<=q;i++)
	{
		while(cur<=n&&a[i].k<=e[cur].w)
		{
			unionn(find(e[cur].u),find(e[cur].v));
			cur++;
		}
		ans[a[i].id]=siz[find(a[i].v)]-1;
	}
	
	for(int i=1;i<=q;i++) cout<<ans[i]<<"\n";
}
