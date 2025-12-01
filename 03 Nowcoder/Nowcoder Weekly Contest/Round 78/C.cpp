#include <bits/stdc++.h>
using namespace std;
int n,m;
void solve()
{
	cin>>n>>m;
	vector<vector<char>>a(n+1,vector<char>(m+1));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
		}
	}
	int res=0;
	map<string,int>mp;
	for(int j=1;j<=m;j++)
	{
		string ans;
		for(int i=1;i<=n;i++)
		{
			if(a[i][j]=='1') ans+='0';
			else ans+='1';
		}
		mp[ans]++;
		res=max(res,mp[ans]);
	}
	cout<<res<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
