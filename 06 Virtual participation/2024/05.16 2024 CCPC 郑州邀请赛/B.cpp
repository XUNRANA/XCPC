#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,ans,sum;
signed main()
{
	cin>>n;
	vector<pair<int,int>>a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i].first,a[i].second=i;
	sort(a.begin()+1,a.end());
	for(int i=1;i<=n;i++)
	{
		if(a[i].second-sum>=a[i].first) 
		{
			ans+=(a[i].second-sum)/a[i].first;
			sum+=(a[i].second-sum)/a[i].first*a[i].first;
		}
	}
	cout<<ans<<'\n';
}
