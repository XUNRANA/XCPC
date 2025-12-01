#include <bits/stdc++.h>
using namespace std;

void solve()
{
	string s;
	cin>>s;
	vector<string>v;
	for(int i=0;i<s.size();i++)
	{
		if(i+1<s.size()) v.push_back(s.substr(i,2));
	}
	sort(v.begin(),v.end());
	for(auto i:v) cout<<i<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

