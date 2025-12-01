#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	int n,k;
	cin>>n>>k;
	priority_queue<int,vector<int>,less<int>>q;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		q.push(x);
		if((n-k-i)%(k+1)==0)
		{
			ans+=q.top();
			q.pop();
		}
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
