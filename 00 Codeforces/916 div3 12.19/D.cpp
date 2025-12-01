#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	int t,n,ans;
	cin>>n;
	priority_queue<pair<int,int>>q1,q2,q3;
	vector<pair<int,int> >a,b,c;
	for(int i=1;i<=n;i++) 
	{
		cin>>t;
		q1.push({t,i});
	}
	for(int i=1;i<=n;i++) 
	{
		cin>>t;
		q2.push({t,i});
	}
	for(int i=1;i<=n;i++) 
	{
		cin>>t;
		q3.push({t,i});
	}
	while(a.size()<3) a.push_back(q1.top()),q1.pop();
	while(b.size()<3) b.push_back(q2.top()),q2.pop();
	while(c.size()<3) c.push_back(q3.top()),q3.pop();
	ans=0;
	for(int i=0;i<=2;i++)
	{
		for(int j=0;j<=2;j++)
		{
			if(a[i].second==b[j].second) continue;
			for(int k=0;k<=2;k++)
			{
				if(c[k].second==a[i].second||c[k].second==b[j].second) continue;
				ans=max(ans,a[i].first+b[j].first+c[k].first);
			}
		}
	}
	cout<<ans<<"\n";
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
}
