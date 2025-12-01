#include <bits/stdc++.h>
using namespace std;
int n,l,sum,ans,lim;
void solve()
{
	cin>>n>>l;
	vector<pair<int,int>>v(n+1);
	for(int i=1;i<=n;i++) cin>>v[i].second>>v[i].first;
	sort(v.begin()+1,v.end());
	ans=0;
	for(int i=1;i<=n;i++)
	{
		multiset<int>s;
		sum=0;
		for(int j=i;j<=n;j++)
		{
			s.insert(v[j].second);
			sum+=v[j].second;
			lim=l-(v[j].first-v[i].first);
			if(lim<0) break;
			while(sum>lim)
			{
				auto it=prev(s.end());
				sum-=*it;
				s.erase(it);
			}
			ans=max(ans,int(s.size()));
		}
	}
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
}
