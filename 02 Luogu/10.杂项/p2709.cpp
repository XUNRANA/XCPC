#include <bits/stdc++.h>
using namespace std;
int n,m,k,B,c[50010],a[50010];
int ans[50010];
int sum;
struct node
{
	int l,r,id;
}q[50010];
bool cmp(node q1,node q2)//按l/B、r排序 
{
	if(q1.l/B!=q2.l/B) return q1.l<q2.l;
	return q1.r<q2.r;
}
void add(int x)//扩展一个数 
{
	sum-=c[x]*c[x];
	c[x]++;
	sum+=c[x]*c[x];
}
void del(int x)//删除一个数 
{
	sum-=c[x]*c[x];
	c[x]--;
	sum+=c[x]*c[x];
}
void solve()
{

	cin>>n>>m>>k;
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
		while(l>q[i].l) add(a[--l]);//左扩展 
		while(r<q[i].r) add(a[++r]);//右扩展 
		while(l<q[i].l) del(a[l++]);//左删除 
		while(r>q[i].r) del(a[r--]);//右删除 
		ans[q[i].id]=sum;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<"\n";

}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
