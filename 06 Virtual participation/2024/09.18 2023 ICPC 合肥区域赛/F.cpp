#include <bits/stdc++.h>
using namespace std;


void solve()
{
	int n;
	map<string,int>mp;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		string s;
		cin>>s;
		mp[s]++;
	}
	for(auto i:mp)
	{
		if(2*i.second>n)
		{
			cout<<i.first<<"\n";
			return ;
		}
	}
	cout<<"uh-oh\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
