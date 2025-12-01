#include <bits/stdc++.h>
using namespace std;
#define int long long
#define lc p<<1
#define rc p<<1|1
#define N 100010
int n,m,op,x,y,k,w[N];
struct node
{
	int l,r,mx,add;
}tr[4*N];
void pushup(int p)
{
	tr[p].mx=max(tr[lc].mx,tr[rc].mx);
}
void build(int p,int l,int r)
{
	tr[p]={l,r,w[l],0};
	if(l==r) return ;//根节点
	int m=l+r>>1;
	build(lc,l,m);//左 
	build(rc,m+1,r);//右 
	pushup(p);//向上更新 
}
int query(int p,int l,int r)
{
	if(l<=tr[p].l&&r>=tr[p].r) return tr[p].mx;//覆盖 
	int mx=0;
	int m=tr[p].l+tr[p].r>>1;// 计算中点
	if(l<=m) mx=max(mx,query(lc,l,r));// 查询左子区间
	if(r>m) mx=max(mx,query(rc,l,r));// 查询右子区间
	return mx;	// 返回合并后的结果
}

signed main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>w[i];
	build(1,1,n);
	while(m--)
	{
		cin>>x>>y;
		cout<<query(1,x,y)<<"\n";
	}
}
