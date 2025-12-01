#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,B,c[50010],a[50010];
int ansl[50010],ansr[50010];
int sum;
struct node
{
	int l,r,id;
}q[50010];

bool cmp(node q1,node q2)//按l/B、r排序 
{
	if(q1.l/B!=q2.l/B) return q1.l<q2.l;
//	if((q1.l/B)&1) return q1.r<q2.r;
	return q1.r<q2.r;
}
int f(int x)
{
	if(x<=1) return 0;
	return x*(x-1)/2;
}
void add(int x)//扩展一个数 
{
	sum-=f(c[x]);
	c[x]++;
	sum+=f(c[x]);
}
void del(int x)//删除一个数 
{
	sum-=f(c[x]);
	c[x]--;
	sum+=f(c[x]);
}
void solve()
{

	cin>>n>>m;
	B=sqrt(n);//块的大小 
	
	for(int i=1;i<=n;i++) cin>>a[i];
	
	for(int i=1;i<=m;i++)
	{
		cin>>q[i].l>>q[i].r;
		q[i].id=i;
	}
	
	sort(q+1,q+1+m,cmp);
	
	for(int i=1,l=1,r=0;i<=m;i++)
	{
		if(q[i].l==q[i].r)
		{
			ansl[q[i].id]=0;
			ansr[q[i].id]=1;
			continue;
		}
		
		while(l>q[i].l) add(a[--l]);//左扩展 
		while(r<q[i].r) add(a[++r]);//右扩展 
		while(l<q[i].l) del(a[l++]);//左删除 
		while(r>q[i].r) del(a[r--]);//右删除 
		int a=sum;
		int b=f(r-l+1);
		int g=__gcd(a,b);
		a/=g;
		b/=g;
		ansl[q[i].id]=a;
		ansr[q[i].id]=b;	
	}
	
	for(int i=1;i<=m;i++) cout<<ansl[i]<<"/"<<ansr[i]<<"\n";

}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
