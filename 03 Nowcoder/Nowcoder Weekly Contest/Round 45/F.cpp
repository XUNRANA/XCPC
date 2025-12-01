#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 1000000007
int n,seed,d[5010],ans;
int rnd()
{
	int ret=seed;
	seed=(seed*7+13)%P;
	return ret%2;
}
void solve()
{
	cin>>n>>seed;
	for(int i=1;i<=n-1;i++)
	{
		for(int j=i+1;j<=n;j++)
		if(rnd()==0) d[i]++;
		else d[j]++;
	}
	if(n<=2)
	{
		cout<<"0\n";
		return ;
	}
	ans=n*(n-1)*(n-2)/6;
	for(int i=1;i<=n;i++) ans-=d[i]*(d[i]-1)/2;
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
