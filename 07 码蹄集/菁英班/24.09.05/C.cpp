#include <bits/stdc++.h>
using namespace std;
#define N 50010
#define M 16
#define lc p<<1
#define rc p<<1|1
bool pa[N][M];
bool a[N][M];
int n,m,q,x1,x2,y11,y2,w;
struct node
{
	int l,r,c1,ans,lz;
}tr[N<<2][M];
void pushup(int p,int j)
{
	tr[p][j].ans=tr[lc][j].ans+tr[rc][j].ans;
	tr[p][j].c1=tr[lc][j].c1+tr[rc][j].c1;
}
void pushdown(int p,int j)
{
	if(tr[p][j].lz!=-1)
	{
		tr[lc][j].lz=tr[p][j].lz;
		tr[rc][j].lz=tr[p][j].lz;
		
		if(tr[p][j].lz) tr[lc][j].ans=tr[lc][j].c1;
		else tr[lc][j].ans=tr[lc][j].r-tr[lc][j].l+1-tr[lc][j].c1;
		
		if(tr[p][j].lz) tr[rc][j].ans=tr[rc][j].c1;
		else tr[rc][j].ans=tr[rc][j].r-tr[rc][j].l+1-tr[rc][j].c1;
		
		tr[p][j].lz=-1;
	}
}
void build(int p,int l,int r,int j)
{
	tr[p][j].l=l;
	tr[p][j].r=r;
	tr[p][j].lz=-1;
	if(l==r)
	{
		tr[p][j].c1=(pa[l][j]==1);
		tr[p][j].ans=(pa[l][j]==0);
		return ;
	}
	int mid=l+r>>1;
	build(lc,l,mid,j);
	build(rc,mid+1,r,j);
	pushup(p,j);
}
void update(int p,int l,int r,int x,int j)
{
	if(tr[p][j].l>=l&&tr[p][j].r<=r)
	{
		tr[p][j].lz=x;
		if(x) tr[p][j].ans=tr[p][j].c1;
		else tr[p][j].ans=tr[p][j].r-tr[p][j].l+1-tr[p][j].c1;
		return ;
	}
	pushdown(p,j);
	int mid=tr[p][j].l+tr[p][j].r>>1;
	if(l<=mid) update(lc,l,r,x,j);
	if(r>mid) update(rc,l,r,x,j);
	pushup(p,j);
}
void solve()
{
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			char ch;
			cin>>ch;
			if(ch=='1') pa[i][j]=1;	
			else pa[i][j]=0;
		}
	}
	for(int j=1;j<=m;j++) build(1,1,n,j);
	while(q--)
	{
		cin>>x1>>x2>>y11>>y2>>w;
		for(int j=y11;j<=y2;j++) update(1,x1,x2,w,j);
		int ans=0;
		for(int j=1;j<=m;j++) ans+=tr[1][j].ans;
		cout<<ans<<"\n";
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
