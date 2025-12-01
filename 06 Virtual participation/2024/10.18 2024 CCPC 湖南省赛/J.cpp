#include <bits/stdc++.h>
using namespace std;
#define int long long
int tr1[100010];
int tr2[100010];
int a[100010];
int b[100010];
int n;
int lowbit(int x)
{
	return x&-x;
}
void add(int i,int x,int *tr)
{
	while(i<=n)
	{
		tr[i]+=x;
		i+=lowbit(i);
	}
}
int sum(int i,int *tr)
{
	int res=0;
	while(i)
	{
		res+=tr[i];
		i-=lowbit(i);
	}
	return res;
}
void push(int x)
{
	add(a[x],1,tr1);
	add(b[x],1,tr2);
}
void del(int x)
{
	add(a[x],-1,tr1);
	add(b[x],-1,tr2);
}
bool ck(int x)
{
	return sum(a[x],tr1)==sum(b[x],tr2);
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		a[x]=i;
	}
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		b[x]=i;
	}
	int ans=0;
	push(1);
	for(int l=1,r=1;l<=n;l++)
	{
		while(r+1<=n&&ck(r+1))
		{
			push(r+1);
			r++;
		}
		ans+=r-l+1;
		del(l);
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
