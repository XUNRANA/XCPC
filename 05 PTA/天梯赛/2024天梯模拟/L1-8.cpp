#include <bits/stdc++.h>
using namespace std;
string ans[110];
int a[11];
int h[11][11];
void solve()
{
	int n,m;
	cin>>n>>m;
	cin.ignore();
	for(int i=1;i<=n;i++)
	{
		string s;
		getline(cin,s);
		ans[i]=s;
	}
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<10;j++)
		{
			int x;
			cin>>x;
			if(x==-1) x=0;
			h[a[i]][j]=x;
		}
	}
	int k;
	cin>>k;
	while(k--)
	{
		int x;
		cin>>x;
		if(!h[x/10][x%10]) cout<<"?\n";
		else cout<<ans[h[x/10][x%10]]<<"\n";
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
} 
