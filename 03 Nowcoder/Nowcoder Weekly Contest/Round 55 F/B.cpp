#include <bits/stdc++.h>
using namespace std;
long long n,res,t,ans;
void solve()
{
	cin>>n;
	res=1;
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		res=res*t%10;
		if(res%10==6) ans++;
	}
	cout<<ans;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

