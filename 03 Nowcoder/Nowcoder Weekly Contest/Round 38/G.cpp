#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 1000010
int n,k,ans,s,res,a[200010],l[N],r[N];
int lowbit(int x)
{
	return x&-x;
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
void add(int i,int x,int *t)
{
	while(i<=1000000)
	{
		t[i]+=x;
		i+=lowbit(i);
	}
}
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) 
	{
		add(a[i],1,r);
		res+=i-query(a[i],r);
	}
	ans=(res>=k);
	for(int i=1,j=1;j<=n;j++)
	{
		add(a[j],-1,r);
		res-=query(a[j]-1,r)+query(1000000,l)-query(a[j],l);
		while(i<=j&&res<k)
		{
			add(a[i],1,l);
			res+=query(a[i]-1,r)+query(1000000,l)-query(a[i],l);
			i++;
		}
		ans+=j-i+1;
	}
	cout<<ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
