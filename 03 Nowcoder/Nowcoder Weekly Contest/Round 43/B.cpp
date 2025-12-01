#include <bits/stdc++.h>
using namespace std;
#define int long long


void solve()
{
	int x,ans=1e9;
	cin>>x;
	vector<int>a;
	for(int i=1;i<=1000000;i++) a.push_back(i*i);
	int i=upper_bound(a.begin(),a.end(),x)-a.begin();
	for(int j=0;j<=10;j++)
	{
		int t1=1e9;
		int t2=1e9;
		
		if(i-j>=0) t1=min(t1,abs(a[i-j]-x));
		if(i+j<a.size()) t2=min(t2,abs(a[i+j]-x));
		
		if(t1%2==0)
		ans=min(ans,t1/2);
		if(t2%2==0)
		ans=min(ans,t2/2);
	}
	cout<<ans;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
