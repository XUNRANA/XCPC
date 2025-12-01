#include <bits/stdc++.h>
using namespace std;
int main()
{
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	string s;
	cin>>s;
	stack<pair<char,int>>st;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='('||st.empty()) st.push({s[i],i});
		else 
		{
			if(st.top().first=='(') st.pop();
			else st.push({s[i],i});
		}
	}
	if(st.size()==0)
	{
		cout<<0<<"\n";
		return 0;
	}
	//(( )) )(
	char a=st.top().first;
	int ca=st.top().second;
	st.pop();
	char b=st.top().first;
	int cb=st.top().second;

	int ans=0;
	if(a=='(')
	{
		for(int i=ca;i<s.size();i++)
		{
			if(s[i]==a) ans++;
		}
	}
	else
	{
		for(int i=cb;i>=0;i--)
		{
			if(s[i]==b) ans++;
		}
	}
	cout<<ans<<"\n";

}
