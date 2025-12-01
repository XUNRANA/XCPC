#include <bits/stdc++.h>
using namespace std;
int ans;
void solve()
{
	string s;
	cin>>s;
	for(auto i:s)
	{
		if(i!='R') ans++;
	}
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
