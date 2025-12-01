#include <bits/stdc++.h>
using namespace std;
#define int long long 
int n,k,m,a[110],ans;
void solve()
{
	cin>>n>>k;
	vector<int>v;
	ans=0;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		ans+=a[i]/k;
		if(a[i]%k!=0) v.push_back(a[i]%k);
	}
	sort(v.begin(),v.end(),greater<int>());
	cin>>m;
	for(auto i:v) 
	{
		if(m>=k-i)
		{
			m-=k-i;
			ans++;
		}
	}
	ans+=m/k;
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
