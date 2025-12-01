#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	string s;
	stack<char>st;
	cin>>s;
	for(auto i:s)
	{
		if(st.empty()||i!=')') st.push(i);
		else if(i==')')
		{
			string ans="";
			while(st.top()!='(') ans=st.top()+ans,st.pop();
			st.pop();
			cout<<ans<<"\n";
		}
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
