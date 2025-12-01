#include <bits/stdc++.h>
using namespace std;


void solve()
{
	string s;
	cin>>s;
	map<char,int>mp;
	for(auto i:s) mp[i]++;
	string t="String";
	int f=1;
	while(f)
	{
		f=0;
		for(auto i:t)
		{
			if(mp[i]) 
			{
				cout<<i;
				mp[i]--;
				f=1;
			}
		}
	}
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}
