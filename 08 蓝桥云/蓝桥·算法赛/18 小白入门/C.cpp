#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int n,k,ans=0;
	cin>>n>>k;
	n-=k;
	for(int i=1;i*i<=n;i++)
	if(n%i==0) 
	{
		if(i>k) ans++;
		if(n/i>k&&n/i!=i) ans++;
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
