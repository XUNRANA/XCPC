#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int m,n,q;
	cin>>m>>n>>q;
	map<string,string>mp;
	for(int i=1;i<=m;i++)
	{
		string pub,pri;
		cin>>pub>>pri;
		mp[pri]=pub;
	}
	
	map<string,set<string>>mp1;
	map<string,set<string>>mp2;
	for(int i=1;i<=n;i++)
	{
		string ip;
		int k;
		cin>>ip>>k;
		while(k--)
		{
			string sn;
			int t;
			cin>>sn>>t;
            mp1[ip].insert(sn);
			while(t--)
			{
				string pub;
				cin>>pub;
				mp2[sn].insert(pub);
			}
		}
	}
	while(q--)
	{
		string sn,ip,pri;
		cin>>sn>>ip>>pri;
		if(mp1[ip].count(sn)&&mp2[sn].count(mp[pri])) cout<<"Yes\n";
		else cout<<"No\n";
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
} 
