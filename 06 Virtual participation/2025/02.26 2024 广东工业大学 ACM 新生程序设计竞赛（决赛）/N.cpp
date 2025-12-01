#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int n;
	cin>>n;
	map<int,string>mp;
	int mx=0;
	for(int i=1;i<=n;i++)
	{
		string s;
		int x;
		cin>>s>>x;
		mp[x]=s;
		mx=max(mx,x);
	}
	cout<<mp[mx]<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
