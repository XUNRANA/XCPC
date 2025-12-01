#include <bits/stdc++.h>
using namespace std;
#define int long long


void solve()
{
	int n,m;
	cin>>n>>m;
	vector<vector<int>>c(n+1,vector<int>(m+1,0));//考核
	vector<vector<int>>w(n+1,vector<int>(m+1,0));//奖励
	vector<int>a(m+1,0);//初始
	vector<int>cnt(n+1,0);
	queue<int>q;
	vector<priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>>pq(m+1);
	for(int j=1;j<=m;j++) cin>>a[j];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++) cin>>c[i][j];
		for(int j=1;j<=m;j++) cin>>w[i][j];
		int t=0;
		for(int j=1;j<=m;j++) 
		{
			if(c[i][j]>a[j]) 
			{
				t++;
				pq[j].push({c[i][j],i});//第j个能力值的 优先队列 最小
			}
		}
		cnt[i]=t;//多少个不足
		if(!t) q.push(i);//可以直接通过
	}
	int res=0;
	while(!q.empty())
	{
		res++;
		auto i=q.front();
		q.pop();
		for(int j=1;j<=m;j++) 
		{
			a[j]+=w[i][j];//能力值提升
			while(pq[j].size()&&a[j]>=pq[j].top().first)
			{
				cnt[pq[j].top().second]--;
				if(cnt[pq[j].top().second]==0) q.push(pq[j].top().second);//可以通过面试了
				pq[j].pop();
			}
		}
	}
	if(res==n) cout<<"YES\n";
	else cout<<"NO\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
