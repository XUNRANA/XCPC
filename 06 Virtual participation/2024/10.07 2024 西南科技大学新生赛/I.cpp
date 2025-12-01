#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	int n,k;
	string s;
	cin>>n>>k;
	cin>>s;
	for(auto i:s)
	{
		if(islower(i))
		{		
			int t=(i-'a'-k+26)%26;
			cout<<char(t+'a');
		}
		else
		{
			int t=(i-'A'-k+26)%26;
			cout<<char(t+'A');
		}
	}
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
