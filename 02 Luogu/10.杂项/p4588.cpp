#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define N 100010
#define lc p<<1
#define rc p<<1|1 
int q,mod,op,m,tr[4*N];
void pushup(int p)
{
	tr[p]=tr[lc]*tr[rc]%mod;
}
void build(int p,int l,int r)
{
	tr[p]=1;
	if(l==r) return ;
	int mid=l+r>>1;
	build(lc,l,mid);
	build(rc,mid+1,r);
	pushup(p);
}
void update(int p,int l1,int r1,int l,int r,int m)
{
	if(l1>=l&&r1<=r) 
	{
		tr[p]=m;
		return ;
	}
	int mid=l1+r1>>1;
	if(l<=mid) update(lc,l1,mid,l,r,m);
	else update(rc,mid+1,r1,l,r,m);
	pushup(p);
}
void solve()
{
	cin>>q>>mod;
	build(1,1,q);
	for(int i=1;i<=q;i++)
	{
		cin>>op>>m;
		if(op==1) update(1,1,q,i,i,m);
		else update(1,1,q,m,m,1);
		cout<<tr[1]<<"\n";
	}
}
signed main()
{
	int T;
	cin>>T;
	while(T--) solve();
}
