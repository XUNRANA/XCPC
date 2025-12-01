#include <bits/stdc++.h>
using namespace std;
#define N 1000010
int n,q,v[N],ans[N],a[N],t[N];
struct node
{
	int l,r,i;
}b[N];
bool cmp(node b1,node b2)
{
	return b1.r<b2.r;
}
int lowbit(int x)
{
	return x&-x;
}
void update(int i,int x)
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
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	cin>>q;
	for(int i=1;i<=q;i++) cin>>b[i].l>>b[i].r,b[i].i=i;
	sort(b+1,b+1+q,cmp);
	int now=1;
	for(int i=1;i<=q;i++)
	{
		for(int j=now;j<=b[i].r;j++)
		{
			if(v[a[j]]) update(v[a[j]],-1);
			update(j,1);
			v[a[j]]=j;
		}
		now=b[i].r+1;
		ans[b[i].i]=sum(b[i].r)-sum(b[i].l-1);
	}
	for(int i=1;i<=q;i++) cout<<ans[i]<<"\n";
}
