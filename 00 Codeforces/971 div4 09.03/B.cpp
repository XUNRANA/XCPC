#include <bits/stdc++.h>
using namespace std;
int ans[510];
void solve()
{
	int n;
	string s;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		s=" "+s;
		for(int j=1;j<=4;j++) if(s[j]=='#') ans[i]=j;
	}
	for(int i=n;i>=1;i--) cout<<ans[i]<<" ";
	cout<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
} 
