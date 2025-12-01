#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	string s;
	cin>>s;
	deque<int>ans;
	for(auto i:s)
	{
		int x=i-'0';
		if(ans.empty()||x<=ans.back()) ans.push_back(x);
		else
		{			
			int j=0;
			stack<int>st;
			while(!ans.empty()&&x-(j+1)>ans.back())
			{
				j++;
				st.push(ans.back());
				ans.pop_back();
			}
			ans.push_back(x-j);
			while(!st.empty()) ans.push_back(st.top()),st.pop();
		}
	}
	for(auto i:ans) cout<<i;
	cout<<"\n";
	

	
	
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
