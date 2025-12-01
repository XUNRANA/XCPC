#include <bits/stdc++.h>
using namespace std;
long long ans,n;
void solve()
{
	ans=0;
	string s;
	set<char>st;
	cin>>n>>s;
	for(int i=0;i<n;i++)
	{
		st.insert(s[i]);
		ans+=st.size();
	}          
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
}
