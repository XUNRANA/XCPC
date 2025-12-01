#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 1000010
int n,nq,l,r,x,a[N],tr[N],ans[N];
vector<pair<pair<int,int>,int>>q[N];
vector<int>g[N];
int lowbit(int x)
{
	return x&-x;
}
void add(int i,int x)
{
	while(i<=N)
	{
		tr[i]+=x;
		i+=lowbit(i);
	}
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
void solve()
{
	cin>>n>>nq;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
        a[i]++;
		g[a[i]].push_back(i);
	}
	
	for(int i=1;i<=nq;i++)
	{
		cin>>l>>r>>x;
        x++;
		q[x].push_back({{l,r},i});
	}
	
	for(int i=100001;i>=1;i--)
	{
		for(auto j:g[i]) add(j,1);
		for(auto j:q[i])
		{
			int k=j.second;
			l=j.first.first;
			r=j.first.second;
			ans[k]=query(r)-query(l-1);
		}
	}
	for(int i=1;i<=nq;i++) cout<<ans[i]<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
