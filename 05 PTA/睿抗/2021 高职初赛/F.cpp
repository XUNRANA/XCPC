#include <bits/stdc++.h>
using namespace std;
#define int long long
int ans[100][100];
void solve()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		string s;
		cin>>s;
		int f=0;
		for(int i=0;i<s.size();i++)
		{
			if(s[i]=='/'||s[i]==';')
			{
				int x=stoi(s.substr(0,i));
				int y=stoi(s.substr(i+1));
				ans[x][y]=1;
				f=1;
				break;
			}
		}
		if(!f)
		{
			int x=stoi(s)/100;
			int y=stoi(s)%100;
			ans[x][y]=1;
		}
	}
	for(int j=n;j>=1;j--)
	{
		for(int i=1;i<=n;i++) 
		if(ans[i][j]) cout<<"#";
		else cout<<".";
		cout<<"\n";
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
} 
