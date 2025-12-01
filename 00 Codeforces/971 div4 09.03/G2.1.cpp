#include <bits/stdc++.h>
using namespace std;
#define N 200010
#define lc p<<1
#define rc p<<1|1
#define int long long

int res,n,k,nq,l,r,a[N],ans[N],ans1[N];

vector<pair<int,int>>g[N];

struct node
{
	int l,r,s,lz;
}tr[N<<2];

void pushup(int p)
{
	tr[p].s=tr[lc].s+tr[rc].s;
}
void build(int p,int l,int r)
{
	tr[p]={l,r,0,-1};
	if(l==r) return ;
	int m=l+r>>1;
	build(lc,l,m);
	build(rc,m+1,r);
	pushup(p);
}
void pushdown(int p)
{
	if(tr[p].lz!=-1)
	{
		int x=tr[p].lz;
		
		tr[lc].lz=x;
		tr[lc].s=(tr[lc].r-tr[lc].l+1)*x;
		
		tr[rc].lz=x;
		tr[rc].s=(tr[rc].r-tr[rc].l+1)*x;
		
		tr[p].lz=-1;
	}
}
void update(int p,int l,int r,int x)
{
	if(l<=tr[p].l&&tr[p].r<=r) 
	{
		tr[p].lz=x;
		tr[p].s=(tr[p].r-tr[p].l+1)*x;
		return ;
	}
	pushdown(p);
	int m=tr[p].l+tr[p].r>>1;
	if(l<=m) update(lc,l,r,x);
	if(r>m) update(rc,l,r,x);
	pushup(p);
}
int query(int p,int l,int r)
{
	if(l<=tr[p].l&&tr[p].r<=r) 
	{
		return tr[p].s;
	}
	pushdown(p);
	int m=tr[p].l+tr[p].r>>1;
	if(r<=m) return query(lc,l,r);
	if(l>m) return query(rc,l,r);
	return (query(lc,l,r)+query(rc,l,r));
}

void solve()
{
	cin>>n>>k>>nq;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		a[i]+=n-i;
	}
	
	
	res=0;
	vector<int>cnt(2*n+2),freq(n+1);
	for(int i=1;i<k;i++)
	{
		freq[cnt[a[i]]]--;//频数-- 
		res=max(res,++cnt[a[i]]);//最大频数为众数 
		freq[cnt[a[i]]]++;//频数++ 
	}
	
	for(int i=k;i<=n;i++)
	{
		freq[cnt[a[i]]]--;
		res=max(res,++cnt[a[i]]);
	
		freq[cnt[a[i]]]++;
		while(freq[res]==0) res--;//自减 
		
		ans[i-k+1]=k-res;
		
		freq[cnt[a[i-k+1]]]--;
		cnt[a[i-k+1]]--;
		freq[cnt[a[i-k+1]]]++;
	}

	
	for(int i=1;i<=n;i++) g[i].clear();	
	
	for(int i=1;i<=nq;i++)
	{
		cin>>l>>r;
		g[l].push_back({r-k+1,i});
	}
	
	build(1,1,n);
	
	
	stack<int>st;
	st.push(n-k+1+1);
	for(int i=n-k+1;i>=1;i--)
	{
		while(st.size()>1&&ans[i]<ans[st.top()]) st.pop();
		
		update(1,i,st.top()-1,ans[i]);		
		
		for(auto j:g[i]) 
		{
			ans1[j.second]=query(1,i,j.first);
		}
		st.push(i);
	}
	for(int i=1;i<=nq;i++) cout<<ans1[i]<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
