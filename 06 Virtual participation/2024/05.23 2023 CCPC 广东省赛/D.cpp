#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,ans,cnt;
void solve()
{
	ans=cnt=0;
	cin>>n>>m;
	vector<pair<int,int>>p(n+1);
	priority_queue<int,vector<int>,less<int>>q;
	for(int i=1;i<=n;i++)
	{
		int a,b;
		cin>>a>>b;
		p[i].first=a;
		p[i].second=b;
		ans+=a;
		if(b>a) q.push(b-a);
	}
	int t=min(m-n,(int)q.size());
	if(t+1==n)
	{
		int mi=1e18;
		int ans1=0,ans2=0;
		for(int i=1;i<=n;i++) ans1+=p[i].second;
		for(int i=1;i<=n;i++) 
		if(p[i].first>p[i].second) ans2+=p[i].first;
		else ans2+=p[i].second,mi=min(mi,p[i].second-p[i].first);
		cout<<max(ans1,ans2-mi)<<'\n';
		return ;
	}
	while(t--)
	{
		ans+=q.top();
		q.pop();
	}
	cout<<ans<<'\n';
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--) solve();  
}
