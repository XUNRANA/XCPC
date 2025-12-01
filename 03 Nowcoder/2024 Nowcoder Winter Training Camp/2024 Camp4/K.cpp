#include <bits/stdc++.h>
using namespace std;
#define int long long
#define lc p<<1
#define rc p<<1|1
#define P 1000000007
#define N 200010
int n,q;
string s;
struct node
{
	int l;
	int r;
	int rb;//第一个B之前R的个数 
	int bn;//最后一堆的方块数 
	int sum;//总方块数 
	int fb;//是否有B命令 
}tr[N<<2];
int ksm(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1) res=res*a%P;
		a=a*a%P;
		b>>=1;
	}	
	return res;
}
node merge(node l,node r)
{
	node res;
	res.l=l.l;
	res.r=r.r;
	res.sum=(l.sum+r.sum+l.bn*(ksm(2,r.rb)-1))%P;
	if(!r.fb&&!l.fb)
	{
		res.bn=res.sum;
		res.fb=0;
	}
	else
	{
		res.fb=1;
		if(!r.fb) res.bn=(l.bn+r.sum+l.bn*(ksm(2,r.rb)-1))%P;
		else res.bn=r.bn;
	}
	if(l.fb) res.rb=l.rb;
	else res.rb=l.rb+r.rb;
	return res;
}
void build(int p,int l,int r)
{
	if(l==r)
	{
		tr[p].l=tr[p].r=l;
		tr[p].sum=1;
		if(s[l]=='Y')
		{
			tr[p].bn=1;
			tr[p].rb=0;
			tr[p].fb=0;	
		}
		else if(s[l]=='B')
		{
			tr[p].bn=1;
			tr[p].rb=0;
			tr[p].fb=1;	
		}
		else 
		{
			tr[p].bn=1;
			tr[p].rb=1;
			tr[p].fb=0;	
		}
		return ;
	}
	int mid=l+r>>1;
	build(lc,l,mid);
	build(rc,mid+1,r);
	tr[p]=merge(tr[lc],tr[rc]);
}

void update(int p,int i,char ch)
{
	if(tr[p].l==i&&tr[p].r==i)
	{
		if(ch=='Y')
		{
			tr[p].bn=1;
			tr[p].rb=0;
			tr[p].fb=0;	
		}
		else if(ch=='B')
		{
			tr[p].bn=1;
			tr[p].rb=0;
			tr[p].fb=1;	
		}
		else if(ch=='R')
		{
			tr[p].bn=1;
			tr[p].rb=1;
			tr[p].fb=0;	
		}
		return ;
	}
	int mid=tr[p].l+tr[p].r>>1;
	if(i<=mid) update(lc,i,ch);
	else update(rc,i,ch);
	tr[p]=merge(tr[lc],tr[rc]);
}

node query(int p,int l,int r)
{
	if(tr[p].l>=l&&tr[p].r<=r)
	return tr[p];
	int mid=tr[p].l+tr[p].r>>1;
	if(r<=mid) return query(lc,l,r);
	if(l>mid) return query(rc,l,r);
	return merge(query(lc,l,r),query(rc,l,r));
}
void solve()
{
	cin>>n>>q;
	cin>>s;
	s=" "+s;
	build(1,1,n);
	while(q--)
	{
		int op;
		cin>>op;
		if(op==1)
		{
			int x;
			char c;
			cin>>x>>c;
			update(1,x,c);
		} 
		else 
		{
			int l,r;
			cin>>l>>r;
			cout<<query(1,l,r).sum<<"\n";
		}
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
