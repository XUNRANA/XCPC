#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 1000000007
#define N 10000001
int f[2*N];
void solve()
{
	string s;
	cin>>s;
	int n=s.size();
	f[1]=f[2]=1;
	for(int i=3;i<=2*n+10;i++) f[i]=(f[i-1]+f[i-2])%P;
	int ans=0,x=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='1')
		{
			ans=(ans+f[x+2*(n-1-i)])%P;
			x++;
		}
	}
	ans=(ans+f[x])%P;
	cout<<ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
