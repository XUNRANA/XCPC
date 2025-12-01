#include <bits/stdc++.h>
using namespace std;
void solve()
{
	long long n,m,a,b,ans;
	cin>>n>>m>>a>>b;
	for(int i=0;i<=min(n/2,m);i++)
	{
		ans=max(ans,i*a+b*min(n-2*i,(m-i)/2));
	}
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
