#include <bits/stdc++.h>
using namespace std;


void solve()
{
	int n;
	cin>>n;
	cin.ignore();
	map<string,vector<string>>mp;
	while(n--)
	{
		string s;
		getline(cin,s);
		string ans="";
		char p=' ';
		for(auto i:s)
		{
			if(p==' '&&i!=' ') ans+=i;
			p=i;
		}
		mp[ans].push_back(s);
	}
	for(auto &i:mp) sort(i.second.begin(),i.second.end());
	int m;
	cin>>m;
	cin.ignore();
	while(m--)
	{
		string s;
		getline(cin,s);
		string ans="";
		char p=' ';
		for(auto i:s)
		{
			if(p==' '&&i!=' ') ans+=i;
			p=i;
		}
		if(!mp.count(ans))
		{
			cout<<s<<"\n";
			continue;
		}
		int f=0;
		for(auto i:mp[ans]) 
		{
			if(f) cout<<"|";
			f=1;
			cout<<i;
		}
		cout<<"\n";
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

