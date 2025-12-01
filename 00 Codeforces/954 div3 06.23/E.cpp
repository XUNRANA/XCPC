#include <bits/stdc++.h>
using namespace std;

#define int long long
void solve()
{
	int n,k;
	cin>>n>>k;
	int ans=0,odd=0;
	map<int,vector<int>>mp;
	for(int i=1;i<=n;i++)
	{
		int a;
		cin>>a;
		mp[a%k].push_back(a);
	}
	for(auto i:mp)
	{
		vector<int>a;
		a=i.second;
		sort(a.begin(),a.end());
		if(a.size()%2==0)
		{
			for(int i=0;i<a.size();i+=2) 
			ans+=(a[i+1]-a[i])/k;
		}
		else 
		{
			odd++;
			int sum=0;
			for(int i=1;i<a.size();i+=2) sum+=(a[i+1]-a[i])/k;
			int res=sum;
			for(int i=0;i+1<a.size();i+=2)
			{
				sum+=(a[i+1]-a[i])/k;
				sum-=(a[i+2]-a[i+1])/k;
				res=min(res,sum);
			}
			ans+=res;
		}
	}
	if(odd>1) ans=-1;
	cout<<ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--) solve();
}
