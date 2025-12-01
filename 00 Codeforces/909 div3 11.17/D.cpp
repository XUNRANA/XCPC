#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,t1,ans;
void solve()
{
	ans=0;
	cin>>n;
	map<int,int>m;
	while(n--)
	{
		cin>>t1;
		if(t1==2) t1=1;
		m[t1]++;
	}
	for(auto i:m) ans+=i.second*(i.second-1)/2;
	cout<<ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
}
