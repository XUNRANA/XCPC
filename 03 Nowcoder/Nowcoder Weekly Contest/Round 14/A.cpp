#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int n;
	string s;
	cin>>n>>s;
	stack<char>st; 
	for(auto i:s)
	{
		if(st.empty()) st.push(i);
		else if(i==st.top()) st.pop();
		else st.push(i);
	}
	if(st.empty())
	{
		cout<<n<<"\n";
		return ;
	}
	vector<char>v(st.size());
	int i=0;
	while(!st.empty())
	{
		v[i++]=st.top();
		st.pop();
	}
	int j=0;
	i=v.size()-1;
	while(v[j]==v[i]&&j<i) j++,i--;
	cout<<n-(i-j+1)<<"\n";
	
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
