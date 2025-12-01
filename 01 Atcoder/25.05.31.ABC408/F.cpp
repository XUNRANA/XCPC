#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 500010
#define lc p<<1
#define rc p<<1|1
struct node
{
	int l,r,mx;
}tr[N<<2];
void pushup(int p)//向上更新 
{
	tr[p].mx=max(tr[lc].mx,tr[rc].mx);
}
void build(int p,int l,int r)
{
	tr[p]={l,r,0};
	if(l==r) return ;
	int m=l+r>>1;
	build(lc,l,m);
	build(rc,m+1,r);
	pushup(p);
}
void update(int p,int x,int k) 
{
	if(tr[p].l==x&&tr[p].r==x)
	{
		tr[p].mx+=k;
		return ;
	}
	int m=tr[p].l+tr[p].r>>1;
	if(x<=m) update(lc,x,k);
	else update(rc,x,k);
    pushup(p);
}

int query(int p,int x,int y)
{
	if(x<=tr[p].l&&tr[p].r<=y) return tr[p].mx;
	int m=tr[p].l+tr[p].r>>1; 
	int mx=0;
	if(x<=m) mx=max(mx,query(lc,x,y));//左子树有部分覆盖 
	if(y>m) mx=max(mx,query(rc,x,y));//右子树有部分覆盖 
	return mx;
}

int idx[N];
int ans[N];
void solve()
{
    int n,d,r;
    cin>>n>>d>>r;
    for(int i=1;i<=n;i++) 
    {
        int x;
        cin>>x;
        idx[x]=i;
    }
    build(1,1,n);
    int aaa=1;
    for(int i=n;i>=1;i--)
    {
        int l1=idx[i]-r;
        l1=max(l1,1ll);
        int r1=idx[i]+r;
        r1=min(r1,n);
        if(i+d<=n) update(1,idx[i+d],ans[i+d]);
        int res=query(1,l1,r1);
        ans[i]=res+1;
        aaa=max(aaa,ans[i]);
    }
    cout<<aaa-1<<"\n";
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}