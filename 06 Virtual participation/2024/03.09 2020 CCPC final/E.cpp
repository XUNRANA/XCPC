#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 998244353
#define N 200010
#define lc p<<1
#define rc p<<1|1
int n,w[N];
string s;
struct node
{
	int l,r,sum,add;
}tr[N*4];

void pushup(int p)//向上更新 
{
	tr[p].sum=tr[lc].sum+tr[rc].sum;
} 
void pushdown(int p)//向下更新 
{
	if(tr[p].add)
	{
		tr[lc].sum=(tr[lc].r-tr[lc].l+1)-tr[lc].sum;
		tr[rc].sum=(tr[rc].r-tr[rc].l+1)-tr[rc].sum;
		tr[lc].add=tr[p].add;
		tr[rc].add=tr[p].add;
		tr[p].add=0;
	}
}
void build(int p,int l,int r)
{
	tr[p]={l,r,w[l],0};
	if(l==r) return ;
	int m=l+r>>1;
	build(lc,l,m);
	build(rc,m+1,r);
	pushup(p);
}
/*
void update(int p,int x,int k)//单点修改 
{//根节点进入，将节点[x,x]更改为k，并更改其所有祖先 
	if(tr[p].l==x&&tr[p].r==x)
	{
		tr[p].sum+=k;//更改 
		return ;
	}
	int m=tr[p].l+tr[p].r>>1;//递归找到叶节点[x,x]
	if(x<=m) update(lc,x,k);
	else update(rc,x,k);
	
	tr[p].sum=tr[lc].sum+tr[rc].sum;//回溯 
}
*/
int query(int p,int x,int y)//区间求和 
{
	if(x<=tr[p].l&&tr[p].r<=y) return tr[p].sum;//全部覆盖，直接返回 
	int m=tr[p].l+tr[p].r>>1;//不是完全覆盖，裂开 
	pushdown(p);
	int sum=0;
	if(x<=m) sum+=query(lc,x,y);//左子树有部分覆盖 
	if(y>m) sum+=query(rc,x,y);//右子树有部分覆盖 
	return sum;
}

void updatelr(int p,int x,int y)
{
	if(x<=tr[p].l&&tr[p].r<=y)//覆盖则修改 
	{
		tr[p].sum=(tr[p].r-tr[p].l+1)-tr[p].sum;
		tr[p].add=1;
		return ;
	}
	int m=tr[p].l+tr[p].r>>1;//不覆盖裂开 
	pushdown(p);
	if(x<=m) updatelr(lc,x,y);
	if(y>m) updatelr(rc,x,y);
	pushup(p);	
} 

signed main()
{
	int n,q,x,y;
	while(cin>>n>>q)
	{
		
		cin>>s;
		for(int i=1;i<=n;i++) w[i]=s[i-1]-'0';
		build(1,1,n);
		while(q--)
		{
			cin>>x>>y;	
			updatelr(1,x,y);
			int l=1,mid,r=n;
			while(l<=n)
			{
				mid=l+r>>1;
				if(query(1,1,m)<query(1,1,r))
			}
			cout<<query(1,1,n)<<"\n";
		} 
	}
}
