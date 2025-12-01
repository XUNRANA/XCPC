#include <bits/stdc++.h>
using namespace std;
void solve()
{
	string s;
	cin>>s;
	int ans=1e9;
	for(int i=0;i<26;i++)
	{
		int sum=0;
		for(auto j:s)
		{
			int t=j-'a';
			sum+=min(abs(t-i),26-abs(t-i));
		}
		ans=min(ans,sum);
	}
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
