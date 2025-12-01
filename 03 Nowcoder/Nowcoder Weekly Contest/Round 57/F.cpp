#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[100010],b[100010],k,q,i,j,x,t;
#define lc p<<1
#define rc p<<1|1
struct node
{
	int l,r,mi;
}tr[400010];
void pushup(int p)//向上更新 
{
	tr[p].mi=min(tr[lc].mi,tr[rc].mi);
}
 
void build(int p,int l,int r)
{
	tr[p]={l,r,b[l]};
	if(l==r) return ;
	int m=l+r>>1;
	build(lc,l,m);
	build(rc,m+1,r);
	pushup(p);
}
void update(int p,int x,int k)//单点修改 
{//根节点进入，将节点[x,x]更改为k，并更改其所有祖先 
	if(tr[p].l==x&&tr[p].r==x)
	{
		tr[p].mi=k;//更改 
		return ;
	}
	int m=tr[p].l+tr[p].r>>1;//递归找到叶节点[x,x]
	if(x<=m) update(lc,x,k);
	else update(rc,x,k);
	pushup(p);
}
int query(int p,int x,int y)
{
	if(x<=tr[p].l&&tr[p].r<=y) return tr[p].mi;//全部覆盖，直接返回 
	int m=tr[p].l+tr[p].r>>1;//不是完全覆盖，裂开 

	int mi=1e18;
	if(x<=m) mi=min(mi,query(lc,x,y));//左子树有部分覆盖 
	if(y>m) mi=min(mi,query(rc,x,y));//右子树有部分覆盖 
	return mi;
}


void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		for(int j=1;j<=a[i];j++) cin>>b[++k];
		a[i]+=a[i-1];
	}
	build(1,1,k);
	cin>>q;
	while(q--)
	{
		cin>>t;
		if(t==1)
		{
			cin>>i>>j>>x;
			update(1,a[i-1]+j,x);
		}
		else 
		{
			cin>>i;
			cout<<query(1,1,a[i])<<"\n";
		}
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
