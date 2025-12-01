#include <bits/stdc++.h>
using namespace std;
void solve()
{
	long long n,k,t,ans=0;
	cin>>n>>k;
	if(k==1) 
	{
		cout<<n<<"\n";
		return ;
	}
	while(n)
	{
		ans+=n%k;
		n/=k;
	}
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
