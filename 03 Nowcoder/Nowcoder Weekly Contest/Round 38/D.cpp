#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k,a[100010];

void solve()
{
	cin>>n>>k;
	vector<int>res;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=2;i<=n;i++) res.push_back(abs(a[i]-a[i-1]));
	sort(res.begin(),res.end());
	if(res.back()==k) cout<<"0\n";
	else if(res.back()<k) cout<<"1\n";
	else 
	{
		int ans=0;
		for(int i=n-2;i>=0;i--)
		{
			if(res[i]<=k) break;
			ans+=(res[i]+k-1)/k-1;
		}
		cout<<ans<<"\n";
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
