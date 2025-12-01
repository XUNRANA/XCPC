#include <bits/stdc++.h>
using namespace std;
#define N 1000010
struct node
{
	int l,r,i;
}b[N];
int n,q,a[N],t[N],v[N],ans[N];
int lowbit(int x)
{
	return x&-x;
}
int update(int i,int x)
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
bool cmp(node b1,node b2)
{
	return b1.r<b2.r;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	cin>>q;
	for(int i=1;i<=q;i++) cin>>b[i].l>>b[i].r,b[i].i=i;
	sort(b+1,b+1+q,cmp);
	int pow=1;
	
	for(int i=1;i<=q;i++)
	{
		for(int j=pow;j<=b[i].r;j++)
		{
			if(v[a[j]]) update(v[a[j]],-1);
			update(j,1);
			v[a[j]]=j;
		}
		pow=b[i].r+1;
		ans[b[i].i]=sum(b[i].r)-sum(b[i].l-1);
	}
	for(int i=1;i<=q;i++) cout<<ans[i]<<"\n";
}
