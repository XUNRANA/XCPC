#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 200010
int n,q,l,r,a[N],d[N];
#define lc p<<1
#define rc p<<1|1
struct node
{
	int l,r,g,mx;//维护区间和、还可以维护区间max，min，gcd，等等 
}tr[N<<2],tr1[N<<2];

void pushup1(int p)//向上更新 
{
	tr1[p].g=__gcd(tr1[lc].g,tr1[rc].g);
}

void build1(int p,int l,int r)
{
	tr1[p]={l,r,d[l],d[l]};
	if(l==r) return ;
	int m=l+r>>1;
	build1(lc,l,m);
	build1(rc,m+1,r);
	pushup1(p);
}

int query1(int p,int x,int y)
{
	if(x<=tr1[p].l&&tr1[p].r<=y) return tr1[p].g;//全部覆盖，直接返回 
	int m=tr1[p].l+tr1[p].r>>1;//不是完全覆盖，裂开 
	int sum=0;
	if(x<=m) sum=__gcd(sum,query1(lc,x,y));//左子树有部分覆盖 
	if(y>m) sum=__gcd(sum,query1(rc,x,y));//右子树有部分覆盖 
	return sum;
}


void pushup(int p)//向上更新 
{
	tr[p].g=__gcd(tr[lc].g,tr[rc].g);
	tr[p].mx=max(tr[lc].mx,tr[rc].mx);
}
 

void build(int p,int l,int r)
{
	tr[p]={l,r,a[l],a[l]};
	if(l==r) return ;
	int m=l+r>>1;
	build(lc,l,m);
	build(rc,m+1,r);
	pushup(p);
}







int query(int p,int x,int y)
{
	if(x<=tr[p].l&&tr[p].r<=y) return tr[p].g;//全部覆盖，直接返回 
	int m=tr[p].l+tr[p].r>>1;//不是完全覆盖，裂开 
	int sum=0;
	if(x<=m) sum=__gcd(sum,query(lc,x,y));//左子树有部分覆盖 
	if(y>m) sum=__gcd(sum,query(rc,x,y));//右子树有部分覆盖 
	return sum;
}

int querymx(int p,int x,int y)
{
	if(x<=tr[p].l&&tr[p].r<=y) return tr[p].mx;//全部覆盖，直接返回 
	int m=tr[p].l+tr[p].r>>1;//不是完全覆盖，裂开 
	int sum=0;
	if(x<=m) sum=max(sum,querymx(lc,x,y));//左子树有部分覆盖 
	if(y>m) sum=max(sum,querymx(rc,x,y));//右子树有部分覆盖 
	return sum;
}

void solve()
{
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<n;i++) d[i]=abs(a[i+1]-a[i]);
	build(1,1,n);
	if(n-1>=1) build1(1,1,n-1);
	
	while(q--)
	{
		cin>>l>>r;
		if(query(1,l,r)==querymx(1,l,r)) cout<<"0 ";
		else 
		{
			if(r-1>=l) cout<<max(query1(1,l,r-1),query(1,l,r))<<" ";
			else cout<<query(1,l,r)<<" ";
		}
	}
	cout<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
