#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
	string s;
	int n;
	cin>>n;
	cin>>s;
	stack<char>st;
	for(auto i:s)
	{
		if(st.empty()||st.top()==i) st.push(i);
		else
		{
			
			if(i==')') st.pop();
			else st.push(i);
		}
	}
	if(st.empty()||st.size()==2) cout<<"Yes\n";
	else cout<<"No\n";
} 
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

