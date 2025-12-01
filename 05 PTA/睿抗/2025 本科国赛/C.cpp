#include <bits/stdc++.h>
using namespace std;
#define int long long
int x[1010][4];
int y[1010][4];
void solve()
{
	string s;
	cin>>s;
	char a=s[0];
	char b=s[1];
	string t;
	cin>>t;
	int n=t.size();
	stack<char>st;
	for(auto i:t)
	{
		if(st.empty()||i!=s[1]||st.top()!=s[0])
		{
			st.push(i);
		}
		else st.pop();
	}
	string ans="";
	while(!st.empty())
	{
		ans=st.top()+ans;
//		cout<<st.top();
		st.pop();
	}
	cout<<(n-ans.size())/2<<" "<<ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
