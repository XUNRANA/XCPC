#include <bits/stdc++.h>
using namespace std;
#define int long long
int sum[400010],mod;
#define lc p<<1
#define rc p<<1|1
void update(int p)
{
	sum[p]=sum[lc]*sum[rc]%mod;
}
void build(int p,int l,int r)
{
	if(l==r) 
	{
		sum[p]=1;
		return ;
	}
	int mid=l+r>>1;
	build(lc,l,mid);
	build(rc,mid+1,r);
	update(p);
}
void change(int p,int l,int r,int lgo,int rgo,int nm)
{
	if(l>=lgo&&r<=rgo)
	{
		sum[p]=nm;
		return ;
	}
	int mid=l+r>>1;
	if(lgo<=mid) change(lc,l,mid,lgo,rgo,nm);
	if(rgo>mid) change(rc,mid+1,r,lgo,rgo,nm);
	update(p);
}
void solve()
{
	int q,op,m;
	cin>>q>>mod;
	build(1,1,q);
	for(int i=1;i<=q;i++)
	{
		cin>>op>>m;
		if(op==1) 
		{
			change(1,1,q,i,i,m);
			sum[1]%=mod;
		}
		else change(1,1,q,m,m,1);
		cout<<sum[1]%mod<<"\n";
	}
}
signed main()
{
	int T;
	cin>>T;
	while(T--) solve();
}
