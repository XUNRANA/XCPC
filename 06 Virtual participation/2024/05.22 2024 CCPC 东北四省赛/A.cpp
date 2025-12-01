#include <bits/stdc++.h>
using namespace std;
#define int long long
int x,k,ans;
void solve()
{
	cin>>x>>k;
	if(x==1) 
	{
		cout<<"1\n";
		return ;
	}
	else ans=1+k;
	while(k--)
	{
		int t=sqrt(x);
		ans++;
		if(t==1) break;
		if(t*t!=x) ans+=k;
		x=t;
	}
	cout<<ans<<'\n';
}
signed main()
{
	int T=1;
	//cin>>T;
	while(T--) solve();
}
