#include <bits/stdc++.h>
using namespace std;
#define N 2000010
int n,c,m,x[N],t[N],l1[N],l2[N],ans[N];
int lowbit(int i)
{
	return i&-i;
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
struct node
{
	int l,r,i,ans;
}q[N];
bool cmp(node q1,node q2)
{
	return q1.r<q2.r;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>c>>m;
	for(int i=1;i<=n;i++) cin>>x[i];
	for(int i=1;i<=m;i++) cin>>q[i].l>>q[i].r,q[i].i=i;
	sort(q+1,q+1+m,cmp);
	for(int i=1,j=1;i<=m;i++)
	{
		for(;j<=q[i].r;j++)
		{
			if(!l1[x[j]]) l1[x[j]]=j;//xj上一次出现 
			else
			{
				if(!l2[x[j]])//xj恰好第二次出现 
				{
					add(l1[x[j]],1);
					l2[x[j]]=l1[x[j]];
					l1[x[j]]=j;
				}
				else
				{
					add(l2[x[j]],-1);
					add(l1[x[j]],1);
					l2[x[j]]=l1[x[j]];
					l1[x[j]]=j;
				}
			}
		}
		ans[q[i].i]=sum(q[i].r)-sum(q[i].l-1);
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<"\n";
}
