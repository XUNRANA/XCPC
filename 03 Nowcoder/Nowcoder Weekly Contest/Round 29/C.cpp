#include <bits/stdc++.h>
using namespace std;
void solve()
{
	string s;
	cin>>s;
	map<char,int>m;
	string p="xiaohong",ans;
	for(int i=0;i<p.size();i++) m[p[i]]--;
	for(int i=0;i<s.size();i++) m[s[i]]++;
	for(auto i:m) 
	{
		while(i.second--) ans+=i.first;
	}
	cout<<"xiaohong"<<ans;

}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

