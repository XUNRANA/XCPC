#include <bits/stdc++.h>
using namespace std;
#define N  200010
struct node
{
	int l,r,op,idx;
}a[2*N];
int n,q,t[N],d[N],res[N];
int lowbit(int x)
{
	return x&-x;
}
void add(int i,int x)
{
	while(i<N)//!!!!!!!!!
	{
		t[i]+=x;
		i+=lowbit(i);
	}
}
int sum(int x)
{
	int res=0;
	while(x)
	{
		res+=t[x];
		x-=lowbit(x);
	}
	return res;
}
bool cmp(node a1,node a2)
{
	if(a1.r==a2.r)
	{
		if(a1.l==a2.l) return a1.op<a2.op;
		return a1.l<a2.l;
	}
	return a1.r>a2.r;
}
void solve()
{
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		int l,r;
		cin>>l>>r;
		d[l]++;
		d[r+1]--;
		a[i]={l,r,0,0};
	}
	for(int i=1;i<N;i++) d[i]+=d[i-1];////!!!!!!!!
	for(int i=1;i<=q;i++)
	{
		int l,r;
		cin>>l>>r;
		res[i]=d[l];
		if(l>r) swap(l,r);
		a[++n]={l,r,1,i};
 	}
 	sort(a+1,a+1+n,cmp);
 	for(int i=1;i<=n;i++)
 	{
 		if(!a[i].op) add(a[i].l,1);
 		else res[a[i].idx]-=sum(a[i].l);
	}
	
	for(int i=1;i<=q;i++) cout<<res[i]<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
} 
