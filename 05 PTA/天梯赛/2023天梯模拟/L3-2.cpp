#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 1000000007
int tr[300010];
vector<int>g[300010];
int n;
int lowbit(int x)
{
	return x&-x;
}
void add(int i,int x)
{
	while(i<=n)
	{
		tr[i]+=x;
		i+=lowbit(i);
	}
}
int query(int l,int r)
{
	int res=0;
	while(r)
	{
		res+=tr[r];
		r-=lowbit(r);
	}
	l--;
	while(l)
	{
		res-=tr[l];
		l-=lowbit(l);
	}
	return res;
}
int ans[300010];
int res;
int jc[300010];
int sz[300010];
int dep[300010];
void init()
{
	jc[0]=1;
	for(int i=1;i<=300000;i++) jc[i]=jc[i-1]*i%P;
}
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
int inv(int x)
{
	return ksm(x,P-2);
}
void dfs(int u,int fa)
{
	ans[u]=query(u+1,n);
	add(u,1);
	int c=0;
	sz[u]=1;
	dep[u]=dep[fa]+1;
	for(auto v:g[u])
	{
		if(v==fa) continue;
		dfs(v,u);
		sz[u]+=sz[v];
		c++;
	}
	res=res*jc[c]%P;
	add(u,-1);
}
void solve()
{
	int rt;
	cin>>n>>rt;
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	res=1;
	dfs(rt,0);
	int fans=0;
	for(int i=1;i<=n;i++) fans=(fans+ans[i]*res%P)%P;
//	cout<<fans<<"\n";
	for(int i=1;i<=n;i++)
	{
		int d=n-(dep[i]-1)-sz[i];
//		cout<<i<<" "<<d<<" "<<d*res%P*inv(4)%P<<"\n";
		fans=(fans+d*res%P*inv(4)%P)%P;
//		cout<<i<<" "<<d<<"\n";
	}
	cout<<fans<<"\n";
}
signed main()
{
	init();
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
