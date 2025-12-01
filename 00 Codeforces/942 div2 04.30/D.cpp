#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,ans;
int gcd(int x,int y)
{
	return y==0? x:gcd(y,x%y);
}
void solve()
{
	ans=0;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		for(int j=i;j<=n;j+=i)
		{
			if((i+j)%(i*(gcd(i,j)))==0) ans++;
		}
	}
	cout<<ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
