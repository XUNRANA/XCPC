#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int n;
	cin>>n;
	map<double,vector<array<int,3>>>mp;
	for(int i=1;i<=n;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		mp[1.0*y/x].push_back({x,y,z});
	}
	int ans=0;
	int cnt=0;
	for(auto i:mp)
	{
		auto a=i.second;
		sort(a.begin(),a.end());
		int p=-1;
		for(auto i:a)
		{
			ans+=i[2];
			if(p==1&&i[2]==1) cnt+=0;
			else cnt++;
			p=i[2];
		}
	}
	cout<<ans<<" "<<cnt<<"\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}
