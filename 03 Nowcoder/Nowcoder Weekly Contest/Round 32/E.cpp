#include <bits/stdc++.h>
using namespace std;
long long ans;
void solve()
{
	string s;
	cin>>s;
	map<vector<int>,int>mp;
	vector<int>c(10);
    mp[c]++;
	for(auto i:s)
	{
		c[i-'0']^=1;
		if(mp.count(c)) ans+=mp[c];
		for(int j=0;j<10;j++) 
		{
			c[j]^=1;
			if(mp.count(c)) ans+=mp[c];
			c[j]^=1;
		}
        mp[c]++;
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

