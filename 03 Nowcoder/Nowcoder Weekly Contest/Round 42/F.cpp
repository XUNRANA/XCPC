#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 1000000007
int dp[100][100];
int ksm(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1) res=res*a%P;
		a=a*a%P;
		b>>=1;
	}	
	return res;
}
int inv(int x)
{
	return ksm(x,P-2)%P;
}
int f(int x,int y)
{
	if(x==0) return 3*y;
	if(y==0) return 3*x;
	if(dp[x][y]) return dp[x][y];
	dp[x][y]=(f(x-1,y)+f(x,y-1)+3)%P*inv(2)%P;
	return dp[x][y];
}
int x,c2,c3;
void solve()
{
	cin>>x;
	while(x%2==0) c2++,x/=2;
	while(x%3==0) c3++,x/=3;
	if(x!=1) cout<<"-1";
	else cout<<f(c2,c3);
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
