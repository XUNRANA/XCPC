#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int n;
	string s;
	stack<char>st;
	cin>>n>>s;
	for(auto i:s)
	{
		if(st.empty()) st.push(i);
		else
		{
			if(i=='c'&&st.top()=='f') st.pop();
			else if(i=='b'&&st.top()=='t') st.pop();
			else st.push(i);
		}
	}
	cout<<st.size()<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}
