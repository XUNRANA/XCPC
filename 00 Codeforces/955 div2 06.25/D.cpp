#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 510
int n,m,k,s0,s1;
int a[N][N];
int f[N][N];
void solve()
{
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>a[i][j];
	s0=s1=0;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) 
	{
		char ch;
		cin>>ch;
		f[i][j]=ch-'0';
		if(f[i][j]) s1+=a[i][j];
		else s0+=a[i][j];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			f[i][j]+=f[i][j-1]+f[i-1][j]-f[i-1][j-1];
		}
	}
	set<int>s;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(i+k-1<=n&&j+k-1<=m)
			{
				int t=f[i+k-1][j+k-1]-f[i-1][j+k-1]-f[i+k-1][j-1]+f[i-1][j-1];
				if(abs(t-(k*k-t))) s.insert(abs(t-(k*k-t)));
			}
		}
	}
	if(s0==s1)
	{
		cout<<"YES\n";
		return ;
	}
	
	int g=0;
	for(auto i:s) g=__gcd(g,i);
	if(g&&abs(s0-s1)%g==0) cout<<"YES\n";
	else cout<<"NO\n";

}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
