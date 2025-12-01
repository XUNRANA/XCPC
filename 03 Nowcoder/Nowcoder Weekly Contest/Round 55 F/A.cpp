#include <bits/stdc++.h>
using namespace std;

void solve()
{
	string s;
	cin>>s;
	set<char>st;
	for(auto i:s) st.insert(i);
	cout<<st.size()-1;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

