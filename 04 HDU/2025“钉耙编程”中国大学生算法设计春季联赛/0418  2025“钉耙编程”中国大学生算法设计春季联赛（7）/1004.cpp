#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	string s;
	cin>>s;
	int n=s.size();
	s=" "+s;
	set<array<int,3>>st;
	for(int i=1,j=1;i<=n;i=j+1,j=i)
	{
		while(j+1<=n&&s[j+1]==s[i]) j++;
		st.insert({i,j,s[i]-'0'});
	}
	vector<vector<int>>a(2,vector<int>(n+1,0));
	for(auto [l,r,c]:st) a[c][l]=r-l+1;

	
}


signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
