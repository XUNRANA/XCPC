#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int n;
	cin>>n;
	if(n==1) cout<<1<<"\n";
	else
	{
		int ans=0;
		map<int,int>mp;
		for(int i=2;i*i<=n;i++) while(n%i==0) mp[i]++,n/=i;
		if(n!=1) mp[n]++;
		for(auto i:mp) ans+=i.first*i.second;
		cout<<ans<<"\n";
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
