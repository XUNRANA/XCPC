#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,t;
void solve()
{
	cin>>n;
	map<int,int>mp;
	map<int,vector<int>>v,u;
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		mp[i]=t;
		v[t>>2].push_back(t);
		u[t>>2].push_back(i);
	}
	for(auto i:v)
	{
		sort(i.second.begin(),i.second.end());
		for(int j=0;j<u[i.first].size();j++) mp[u[i.first][j]]=i.second[j];
	}
	for(int i=1;i<=n;i++) cout<<mp[i]<<" ";
	cout<<"\n";
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
