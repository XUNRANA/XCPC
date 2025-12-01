#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int n;
	string s;
	cin>>n>>s;
	set<char>st;
	for(auto i:s) st.insert(i);
	vector<char>v;
	for(auto i:st) v.push_back(i);
	map<char,char>mp;
	for(int i=0;i<v.size();i++) mp[v[i]]=v[v.size()-1-i];
	string ans="";
	for(auto i:s) ans+=mp[i];
	cout<<ans<<"\n";
	//codefrs
//	cdefors
//	codeforces
//	serofedsoc
	
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
