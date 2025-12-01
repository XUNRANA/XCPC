#include <bits/stdc++.h>
using namespace std;
void solve()
{
	string s,t;
	cin>>s>>t;
	int j=0;
	for(auto i:s)
	{
		if(j<t.size()&&i==t[j]) j++;
	}
	if(j==t.size()) cout<<"Lucky!\n";
	else cout<<"QAQ Unlucky!\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
