#include <bits/stdc++.h>
using namespace std;
void solve()
{
	long long n,x,t,ans=0;
	cin>>n>>x;
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		if(x==0) continue;
		ans+=t;
		if(x>0) x-=t;
		else x+=t;
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
