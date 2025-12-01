#include <bits/stdc++.h>
using namespace std;
string s;
void solve()
{
	cin>>s;
	stack<int>l,u;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='b')
		{
			if(!l.empty()) l.pop();
		}
		else if(s[i]=='B')
		{
			if(!u.empty()) u.pop();
		}
		else
		{
			if(islower(s[i])) l.push(i);
			else u.push(i);
		}
	}
	set<int>st;
	while(!l.empty())
	{
		st.insert(l.top());
		l.pop();
	}
	while(!u.empty())
	{
		st.insert(u.top());
		u.pop();
	}
	for(auto i:st) cout<<s[i];
	cout<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
}
