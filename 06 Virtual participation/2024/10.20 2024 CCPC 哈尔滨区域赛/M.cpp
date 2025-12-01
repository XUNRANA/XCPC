#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	int n;
	cin>>n;
	vector<int>a;
	for(int i=1;i*i<=n;i++)
	{
		if(n%i==0)
		{
			a.push_back(i);
			a.push_back(n/i);
		}
	}
	sort(a.begin(),a.end());
	int ans=0;
	for(int i=1;i<a.size();i++) ans+=(a[i]-a[i-1])*n/a[i-1];
	ans++;
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
