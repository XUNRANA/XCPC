#include <bits/stdc++.h>
using namespace std;
int n,m,a[1000010],b[1000010],tr[1000010],ans[100010];
int lowbit(int x)
{
	return x&-x;
}
void add(int i,int x)
{
	while(i<=n)
	{
		tr[i]^=x;
		i+=lowbit(i);
	}
}
int query(int i)
{
	int res=0;
	while(i)
	{
		res^=tr[i];
		i-=lowbit(i);
	}
	return res;
}

struct qu{
	int l,r,i;
}q[100010];
bool cmp(qu q1,qu q2)
{
	return q1.r<q2.r;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],b[i]=b[i-1]^a[i];
	cin>>m;
	for(int i=1;i<=m;i++) 
	{
		cin>>q[i].l>>q[i].r;
		q[i].i=i;
	}
	sort(q+1,q+1+m,cmp);
	map<int,int>mp;
	int j=1;
	for(int i=1;i<=m;i++)
	{
		while(j<=n&&j<=q[i].r)
		{
			if(mp.count(a[j])) add(mp[a[j]],a[j]);
			mp[a[j]]=j;
			add(mp[a[j]],a[j]);
			j++;
		}
		ans[q[i].i]=query(q[i].r)^query(q[i].l-1)^b[q[i].r]^b[q[i].l-1];
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
