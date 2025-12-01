#include <bits/stdc++.h>
using namespace std;

string p="chatgpt";
void solve()
{
	int n;
	cin>>n;
	map<string,int>mp;
	while(n--)
	{
		string s;
		cin>>s;
		cin.ignore();
		string t;
		getline(cin,t);
		for(auto &i:t) if(isupper(i)) i=tolower(i);
		int cnt=0;
		for(int i=0;i<t.size();i++)
		{
			if(i+6<t.size()&&t.substr(i,7)==p) cnt++;
		}
		if(cnt) mp[s]+=cnt;
	}
	vector<pair<int,string>>a;
	
	for(auto i:mp) a.push_back({-i.second,i.first});
	sort(a.begin(),a.end());
	for(int i=0;i<min(3,(int)a.size());i++)
	{
		cout<<a[i].second<<" "<<-a[i].first<<"\n";
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
