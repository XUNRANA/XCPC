#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 1000000007
int n,k,ans;
string s;
int p[1010],C[1010][1010];
void init()
{
	for(int i=0;i<=1000;i++)
	{
		for(int j=0;j<=i;j++)
		{
			if(!j) C[i][j]=1;
			else C[i][j]=(C[i-1][j]+C[i-1][j-1])%P;
		}
	}
	p[1]=1;
	for(int i=2;i<=1000;i++) p[i]=p[i-1]*10%P;
}
void solve()
{
	init();

	cin>>n>>k;
	cin>>s;
	s=" "+s;
	for(int i=1;i<=n;i++) 
	{
		for(int j=1;j<=min(k,i);j++)
		{
			if(i+k-j>n) continue;
			ans=(ans+p[k-j+1]*(s[i]-'0')%P*C[i-1][j-1]%P*C[n-i][k-j]%P)%P;
		}
	}
	cout<<ans<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
