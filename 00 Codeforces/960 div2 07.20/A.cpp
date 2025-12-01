#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int n,t;
	cin>>n;
	map<int,int>mp;
	for(int i=1;i<=n;i++) cin>>t,mp[t]++;
	for(auto i:mp) 
	if(i.second&1) 
	{
		cout<<"YES\n";
		return ;
	}
	cout<<"NO\n";
	
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--) solve();
}
