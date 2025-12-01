#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define N 200010
#define lc p<<1
#define rc p<<1|1
struct node
{
	int l,r,g;
}tr[N<<2];
int a[N];
void pushup(int p)
{
	tr[p].g=__gcd(tr[lc].g,tr[rc].g);
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
void update(int p,int l,int r,int x)
{
	if(tr[p].l==l&&tr[p].r==r)
	{
		tr[p].g=x;
		return ;
	}
	int m=tr[p].l+tr[p].r>>1;
	if(l<=m) update(lc,l,r,x);
	else update(rc,l,r,x);
	pushup(p);
}
int g[N];
void init()
{
	for(int i=1;i<=2e5;i++)
	{
		for(int j=i;j<=2e5;j+=i)
		{
			g[j]++;
		}
	}
}
void solve()
{
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>a[i];
	
	build(1,1,n);
	for(int i=1;i<n;i++) if(a[i]>a[i+1]) update(1,i,i,i);
	
	
	if(tr[1].g==0) cout<<n<<"\n";
	else cout<<g[tr[1].g]<<"\n";
	while(q--)
	{
		int op,x;
		cin>>op>>x;
		a[op]=x;
		for(int i=max(1ll,op-1);i<=min(op,n-1);i++)
		{
			if(a[i]>a[i+1]) update(1,i,i,i);
			else update(1,i,i,0);
		}
		if(tr[1].g==0) cout<<n<<"\n";
		else cout<<g[tr[1].g]<<"\n";
	}
}

signed main()
{
	init();
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
