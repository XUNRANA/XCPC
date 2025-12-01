#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,k,d,ans,t;
int a[200010];
void solve()
{
	cin>>n>>m>>k>>d;
	vector<int>v;
	while(n--)
	{
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> >q;
		for(int i=1;i<=m;i++) cin>>a[i],a[i]+=1;
		q.push({a[1],1});
		q.push({a[1]+a[2],2});
		for(int i=3;i<=m;i++) 
		{
			while(i-q.top().second-1>d) q.pop();
			t=q.top().first;
			q.push({t+a[i],i});
			if(i==m) v.push_back(t+a[i]);
		}
	}
	
	for(int i=1;i<v.size();i++) v[i]+=v[i-1];
	ans=v[k-1];
	for(int i=k;i<v.size();i++) ans=min(ans,v[i]-v[i-k]);
	cout<<ans<<"\n";
	
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t1;
	cin>>t1;
	while(t1--) solve();
}
