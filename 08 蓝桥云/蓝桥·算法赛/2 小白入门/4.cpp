#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,s,t;
int fx(int x)
{
	int res=0;
	if(x<0) return 0;
	for(int i=1;i<=m;i++)
	{
		if(i<=x) res+=n;
		else res+=(n/i)*(x+1)+min(n%i,x);
	}
	return res;
}

void solve()
{
	cin>>n>>m>>s>>t;
	cout<<fx(t)-fx(s-1)<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
} 
