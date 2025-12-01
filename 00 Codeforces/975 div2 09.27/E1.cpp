#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 200010
vector<int>g[N],f[N];
int cnt[N];
int n,w,cur,s,sum,x,y;
void dfs(int u)
{
	cur++;
	for(auto v:g[u])
	{                         
		//f[v]存储：进入以v为根节点的子树的前一个节点（p）的时间戳、 以v为根节点的子树中的节点（s）的最大的时间戳
		//当钦定以v为儿子的边时，会影响p->v 以及s->(s+1)
		//所以cnt[p]--
		//所以cnt[s]--
		f[v].push_back(cur);
		cnt[cur]++;
		
		dfs(v);
		
		f[v].push_back(cur);
		cnt[cur]++;
	}
}
void solve()
{
	cin>>n>>w;
	for(int i=1;i<=n;i++) g[i].clear(),f[i].clear(),cnt[i]=0;
	for(int i=2;i<=n;i++)
	{
		cin>>x;
		g[x].push_back(i);
	}
	cur=0;
	dfs(1);
	s=n;
	sum=0;
//	for(int i=1;i<=n;i++)
//	{
//		cout<<"cnt:"<<i<<" "<<cnt[i]<<"\n";
//		cout<<i<<"\n";
//		for(auto j:f[i]) cout<<j<<" ";
//		cout<<"\n";
//	}
	for(int i=2;i<=n;i++)
	{
		cin>>x>>y;
		sum+=y;
		for(auto j:f[x])
		{
			cnt[j]--;
			if(cnt[j]==0) s--;
		}
		cout<<2*sum+s*(w-sum)<<" ";
	}
	cout<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
