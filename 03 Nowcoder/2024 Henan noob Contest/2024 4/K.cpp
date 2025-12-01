#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 100010
int n,m,a[20010],t1[N],t2[N],ans;
int lowbit(int x)
{
	return x&-x;
}
int query(int x,int *t)
{
	int res=0;
	while(x)
	{
		res+=t[x];
		x-=lowbit(x);
	}
	return res;
}
void update(int i,int x,int *t)
{
	while(i<=m)
	{
		t[i]+=x;
		i+=lowbit(i);
	}
}
void solve()
{
    ans=0;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	m=100000;
    for(int i=1;i<=m;i++) t1[i]=t2[i]=0;
	update(a[1],1,t1);
	for(int i=n;i>2;i--) update(a[i],1,t2);
	for(int i=2;i<=n-1;i++)
	{
		ans+=query(a[i],t1)*(query(m,t2)-query(a[i]-1,t2));

		ans+=query(a[i],t2)*(query(m,t1)-query(a[i]-1,t1));

        ans-=(query(a[i],t2)-query(a[i]-1,t2))*(query(a[i],t1)-query(a[i]-1,t1));

		update(a[i],1,t1);
        update(a[i+1],-1,t2);
	}
	cout<<ans<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
