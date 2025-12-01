#include <bits/stdc++.h>
using namespace std;
void solve()
{
	string s;
	int ans=0,n;
	map<int,int>mp;
	cin>>n>>s;
	for(auto i:s) mp[i-'A']++;
	for(int i=0;i<4;i++) ans+=min(n,mp[i]);
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
