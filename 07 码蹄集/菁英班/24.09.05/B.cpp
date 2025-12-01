#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,nq,tl[500010],tr[500010],b[500010];
int ans;
int lowbit(int x)
{
	return x&-x;
}
void add(int i,int x,int *t)
{
	while(i<=n)
	{
		t[i]+=x;
		i+=lowbit(i);
	}
}
int query(int i,int *t)
{
	int res=0;
	while(i)
	{
		res+=t[i];
		i-=lowbit(i);
	}
	return res;
}

struct node
{
	int x,i;
}a[500010];
bool cmpx(node a1,node a2)
{
	return a1.x<a2.x;
}
bool cmpi(node a1,node a2)
{
	return a1.i<a2.i;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].x,a[i].i=i;
	sort(a+1,a+1+n,cmpx);
	for(int i=1;i<=n;i++) a[i].x=i;
	sort(a+1,a+1+n,cmpi);
	for(int i=1;i<=n;i++) b[i]=a[i].x;
	
	for(int i=1;i<=n;i++) add(b[i],1,tr);
	
	for(int i=1;i<=n;i++)
	{
		add(b[i],-1,tr);	
		ans+=(query(n,tl)-query(b[i],tl))*query(b[i],tr);
		add(b[i],1,tl);
	}
	cout<<ans<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
} 
