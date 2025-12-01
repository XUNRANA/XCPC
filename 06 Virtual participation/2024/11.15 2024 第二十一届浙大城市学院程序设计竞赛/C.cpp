#include <bits/stdc++.h>  
using namespace std;
#define lc p<<1
#define rc p<<1|1
#define N 200010
int inf=0x3f3f3f3f;
struct node
{
	int l,r,x;
}tr[N<<2];
int a[N],tot;
void pushup(int p)
{
	tr[p].x=min(tr[lc].x,tr[rc].x);
}
void build(int p,int l,int r)
{
	tr[p]={l,r,a[l]};
	if(l==r) return ;
	int m=l+r>>1;
	build(lc,l,m);
	build(rc,m+1,r);
	pushup(p);
}
int query(int p,int l,int r)
{
	
	if(tot) tot+=tot-1;
	tot++;
//	cout<<p<<" "<<tr[p].l<<" "<<tr[p].r<<"++\n";
	if(tr[p].l>r||tr[p].r<l) return inf;
	if(tr[p].l>=l&&tr[p].r<=r) return tr[p].x;
	int m=tr[p].l+tr[p].r>>1;
	return min(query(lc,l,r),query(rc,l,r));
}
//1 3 5
//1 4 10
void solve()
{
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>a[i];
	build(1,1,n);
	for(int i=1;i<=4*n;i++)  cout<<i<<" "<<tr[i].l<<" "<<tr[i].r<<" "<<tr[i].x<<"\n";
	while(q--)
	{
		int l,r;
		cin>>l>>r;
		tot=0;
		query(1,l,r);
		cout<<tot<<"\n";
//		cout<<inf<<"\n";
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
} 
