#include <bits/stdc++.h>
using namespace std;
int a[6];
int b[6];
void solve()
{
	int n;
	cin>>n;
	
	map< pair<string,int>,int>is;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=5;j++)
		{
			string s;
			cin>>s;
			is[{s,j}]=1;
		}
	}
		
	int m;
	cin>>m;

	
	for(int i=1;i<=m;i++)
	{
		string s;
		int pos;
		cin>>s>>pos;
		a[pos]++;
		if(is.count({s,pos})) b[pos]++;
	}
	int ans1=1e9;
	int ans2=0;
	for(int i=1;i<=5;i++) ans1=min(ans1,a[i]);
	for(int i=1;i<=5;i++) ans2+=b[i];
	cout<<min(ans1,ans2)<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
