#include <bits/stdc++.h>
using namespace std;


void solve()
{
	int n,m,k;
	cin>>n>>m>>k;
	map<string,vector<pair<int,int>> >mp;
	for(int i=1;i<=n;i++)
	{
		string s;
		cin>>s;
		for(int j=0;j<m;j++)
		{
			string t=s.substr(j*k,k);
			mp[t].push_back({i,j+1});
		}
	}
	for(auto i:mp) 
	if(i.second.size()==1)
	{
		cout<<i.second[0].first<<" "<<i.second[0].second<<"\n";
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
