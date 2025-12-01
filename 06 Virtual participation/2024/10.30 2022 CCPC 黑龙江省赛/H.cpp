#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	int j=1;
	stack<int>st;
	vector<int>ans;
	for(auto i:s)
	{
		if(i=='(') st.push(j);
		else 
		{
			if(i==')') ans.push_back(j),ans.push_back(st.top()),st.pop();
			else ans.push_back(j);
		}
		j++;
	}
	while(!st.empty())
	{
		ans.push_back(st.top());
		st.pop();
	}
	for(auto i:ans) cout<<i<<" ";
	cout<<"\n";
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
