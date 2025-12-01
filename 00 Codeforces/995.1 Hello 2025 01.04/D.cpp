#include <bits/stdc++.h>
using namespace std;
#define N 200010
#define lc p<<1
#define rc p<<1|1
struct node
{
	int l,r;
    int v1;//x+i的max
    int v11;//x+i的min
    int v2;//x-i的max
    int v22;//x-i的min
    int ans1;
    int ans2;
}tr[N<<2];
int a[N];
void pushup(int p)//向上更新 
{
	tr[p].v1=max(tr[lc].v1,tr[rc].v1);
    tr[p].v2=max(tr[lc].v2,tr[rc].v2);
    tr[p].v11=min(tr[lc].v11,tr[rc].v11);
    tr[p].v22=min(tr[lc].v22,tr[rc].v22);
    tr[p].ans1=max({tr[lc].v1-tr[rc].v11,tr[lc].ans1,tr[rc].ans1});
    tr[p].ans2=max({tr[rc].v2-tr[lc].v22,tr[lc].ans2,tr[rc].ans2});
}
void build(int p,int l,int r)
{
    //a[l]-a[r]-(r-l) ====(a[l]+l)-(a[r]+r)
    //a[r]-a[l]-(r-l) ====(a[r]-r)-(a[l]-l)
	tr[p]={l,r,a[l]+l,a[l]+l,a[l]-l,a[l]-l,0,0};
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
		tr[p].v1=k+x;//更改
        tr[p].v11=k+x;
        tr[p].v2=k-x;
        tr[p].v22=k-x;
		return ;
	}
	int m=tr[p].l+tr[p].r>>1;//递归找到叶节点[x,x]
	if(x<=m) update(lc,x,k);
	else update(rc,x,k);
	pushup(p);
}
void solve()
{
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i];
    build(1,1,n);
    cout<<max(tr[1].ans1,tr[1].ans2)<<"\n";
    while(q--)
    {
        int i,x;
        cin>>i>>x;
        update(1,i,x);
        cout<<max(tr[1].ans1,tr[1].ans2)<<"\n";
    }
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
