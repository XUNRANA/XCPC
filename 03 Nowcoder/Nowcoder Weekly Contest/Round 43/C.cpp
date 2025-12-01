#include <bits/stdc++.h>
using namespace std;
#define int long long
string s;
int h,ans=1e9;
void solve()
{
	cin>>s;
	for(auto i:s) if(isupper(i)) h++;
	for(int i=0;i<s.size();i++)
	{
		if(isupper(s[i])) h--;
		else h++;
		if(i!=s.size()-1)
		ans=min(ans,h);
	}
	cout<<ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
