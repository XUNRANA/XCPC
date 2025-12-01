#include <bits/stdc++.h>
using namespace std;
#define N 500010
#define mod 998244353
#define int long long 
int n,c,cur,cnt,lst,ans,len,L[N],R[N];
int ksm(int a,int b,int p)
{
	int res=1;
	while(b)
	{
		if(b&1) res=res*a%p;
		a=a*a%p;
		b/=2;
	}
	return res;
}
int C(int n,int m,int p)
{
	if(m<0||n<m) return 0;
	if(!m) return 1;
	m=min(m,n-m);
	int a=1,b=1;
	for(int i=1;i<=m;i++)
	{
		a=a*(n-i+1)%p;
		b=(b*i)%p;
	}
	return a*ksm(b,p-2,p)%p;
}
struct node
{
	int val,t;
}a[N];
void dfs(int x)
{
	if(x==-1) return ;
	dfs(L[x]);
	a[x].t=cur++;
	dfs(R[x]);
}
void solve()
{
	cnt=cur=0;
	cin>>n>>c;
	for(int i=1;i<=n;i++) cin>>L[i]>>R[i]>>a[i].val;
	dfs(1);
	sort(a+1,a+1+n,[](node a1,node a2){return a1.t<a2.t;});
	ans=lst=1;
	a[n+1].val=c; 
	for(int i=1;i<=n+1;i++)
	{
		if(a[i].val==-1) cnt++;
		else
		{
			len=a[i].val-lst+1;
			ans=ans*C(cnt+len-1,len-1,mod)%mod;
			lst=a[i].val;
			cnt=0;
		}
	}
	cout<<ans<<"\n";
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
}
