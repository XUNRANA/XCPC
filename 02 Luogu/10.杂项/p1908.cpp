#include <bits/stdc++.h>
using namespace std;
#define int long long
struct node
{
	int v,i,nv;
}a[500010];
int n,ans,t[500010];
int lowbit(int x)
{
	return x&-x;
}
void add(int i,int x)
{
	while(i<=n)
	{
		t[i]+=x;
		i+=lowbit(i);
	}
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
bool cmpv(node a1,node a2)
{
	return a1.v<a2.v;
}
bool cmpi(node a1,node a2)
{
	return a1.i<a2.i;
}
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].v,a[i].i=i;
	sort(a+1,a+1+n,cmpv);
	a[1].nv=1;
	for(int i=2;i<=n;i++) if(a[i].v==a[i-1].v) a[i].nv=a[i-1].nv;
	else a[i].nv=a[i-1].nv+1;
	sort(a+1,a+1+n,cmpi);
	for(int i=1;i<=n;i++) 
	{
		add(a[i].nv,1);
		ans+=i-sum(a[i].nv);
	}
	cout<<ans<<'\n';
}
