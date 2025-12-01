#include <bits/stdc++.h>
using namespace std;
#define N 100010
int n,m,t,l,r,tr[N];
long long ans;
int lowbit(int x)
{
	return x&-x;
}
int query(int i)
{
	int res=0;
	while(i)
	{
		res+=tr[i];
		i-=lowbit(i);
	}
	return res;
}
void add(int i,int x)
{
	while(i<N)
	{
		tr[i]+=x;
		i+=lowbit(i);
	}
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		ans+=i-1-query(t);
		add(t,1);
	}
	ans&=1;
	cin>>m;
	while(m--)
	{
		cin>>l>>r;
		if(((r-l+1)/2)&1) ans^=1;
		cout<<ans<<"\n";
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

