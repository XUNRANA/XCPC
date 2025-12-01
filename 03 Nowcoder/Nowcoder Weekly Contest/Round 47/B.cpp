#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[100010][26];
void solve()
{
	int n;
	string s;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		for(auto j:s)
		{
			a[i][j-'a']++;
		}
	}
	for(int j=0;j<26;j++)
	{
		int f=1;
		for(int i=1;i<=n;i++)
		if(a[i][j]==0) f=0;
		if(f==1)
		{
			cout<<char('a'+j);
			return ;
		}
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
