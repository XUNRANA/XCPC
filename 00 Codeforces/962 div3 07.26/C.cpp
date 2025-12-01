#include <bits/stdc++.h>
using namespace std;
#define int long long 
int n,q,l,r,ans,c[200010][26],d[200010][26];
string a,b;
void solve()
{
	cin>>n>>q;
	cin>>a>>b;
	a=" "+a;
	b=" "+b;
	for(int i=1;i<=n;i++) 
	{
		for(int j=0;j<26;j++)
		c[i][j]=c[i-1][j]+(j==a[i]-'a');
	}
	for(int i=1;i<=n;i++) 
	{
		for(int j=0;j<26;j++)
		d[i][j]=d[i-1][j]+(j==b[i]-'a');
	}
	while(q--)
	{
		cin>>l>>r;
		ans=0;
		for(int i=0;i<26;i++) ans+=abs((c[r][i]-c[l-1][i])-(d[r][i]-d[l-1][i]));
		cout<<ans/2<<"\n";
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
