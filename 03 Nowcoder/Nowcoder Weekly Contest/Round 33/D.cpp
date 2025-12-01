#include <bits/stdc++.h>
using namespace std;
int n,ans,t,p=-1,pc;
void solve()
{
	cin>>n;
	map<int,int>mp;
	for(int i=1;i<=n;i++) 
	{
		cin>>t;
		mp[t]++;
	}
	for(auto i:mp)
	{
		if(i.first!=p+1) ans+=i.second;
		else ans+=max(i.second-pc,0);
		p=i.first;
		pc=i.second;
	}
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

