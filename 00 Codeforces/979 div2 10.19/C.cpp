#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	int n;
	string s;
	cin>>n>>s;
	if(s[0]=='1'||s[n-1]=='1') cout<<"YES\n";
	else
	{
		for(int i=0;i+1<n;i++)
		{
			if(s[i]=='1'&&s[i+1]=='1')
			{
				cout<<"YES\n";
				return ;
			}
		}
		cout<<"NO\n";
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
