#include <bits/stdc++.h>
using namespace std;
#define int long long
#define lc p<<1
#define rc p<<1|1
#define N 100010
int n,m,op,x,y,k,w[N];
struct node
{
	int l,r,sum,add;
}tr[4*N];
void pushup(int p)
{
	tr[p].sum=tr[lc].sum+tr[rc].sum;
}
void pushdown(int p)
{
	if(tr[p].add)
	{
		tr[lc].sum+=tr[p].add*(tr[lc].r-tr[lc].l+1);
		tr[rc].sum+=tr[p].add*(tr[rc].r-tr[rc].l+1);
		tr[lc].add+=tr[p].add;
		tr[rc].add+=tr[p].add;
		tr[p].add=0;
	}
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
	if(l<=tr[p].l&&r>=tr[p].r) return tr[p].sum;//覆盖 
	pushdown(p);// 下推懒标记
	int sum=0;
	int m=tr[p].l+tr[p].r>>1;// 计算中点
	if(l<=m) sum+=query(lc,l,r);// 查询左子区间
	if(r>m) sum+=query(rc,l,r);// 查询右子区间
	return sum;	// 返回合并后的结果
}

void update(int p,int x,int k)//点修改 
{
	if(tr[p].l==x&&tr[p].r==x)// 更新叶子节点
	{
		tr[p].sum=k;// 将值更新为 k
		return ;
	}
	int m=tr[p].l+tr[p].r>>1;// 计算中点
	if(x<=m) update(lc,x,k);// 更新左子树
	else update(rc,x,k); // 更新右子树
	pushup(p);// 向上合并，更新当前节点
}
void updatelr(int p,int l,int r,int k)
{
	if(l<=tr[p].l&&r>=tr[p].r)//覆盖 
	{
		tr[p].sum+=(tr[p].r-tr[p].l+1)*k;// 更新当前节点的值
		tr[p].add+=k;// 设置懒标记
		return ;
	}
	pushdown(p);// 下推懒标记
	int m=tr[p].l+tr[p].r>>1;// 计算中点
	if(l<=m) updatelr(lc,l,r,k);// 更新左子区间
	if(r>m) updatelr(rc,l,r,k); // 更新右子区间
	pushup(p);// 向上合并，更新当前节点
}

signed main()
{
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) cin>>w[i];
	build(1,1,n);
	while(m--)
	{
		cin>>op;
		if(op==1)
		{
			cin>>x>>y>>k;
			updatelr(1,x,y,k);
		}
		else
		{
			cin>>x>>y;
			cout<<query(1,x,y)<<"\n";
		}
	}
}
