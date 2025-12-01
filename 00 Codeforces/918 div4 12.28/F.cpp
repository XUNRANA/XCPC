#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,t[200010],ans;
struct node 
{
	int l,r;
}a[200010];
bool cmpl(node a1,node a2)
{
	return a1.l<a2.l;
}
bool cmpr(node a1,node a2)
{
	return a1.r<a2.r;
}
int lowbit(int x)
{
	return x&-x;
}
int sum(int i)
{
	int res=0;
	while(i)
	{
		res+=t[i];
		i-=lowbit(i);
	}
	return res;
}
void add(int i,int x)
{
	while(i<=n)
	{
		t[i]+=x;
		i+=lowbit(i);
	}
}
void solve()
{
	ans=0;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].l>>a[i].r;
	sort(a+1,a+1+n,cmpr);
	for(int i=1;i<=n;i++) a[i].r=i,t[i]=0;
	sort(a+1,a+1+n,cmpl);
	for(int i=1;i<=n;i++)
	{
		add(a[i].r,1);
		ans+=a[i].r-sum(a[i].r);
	}
	cout<<ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
}
