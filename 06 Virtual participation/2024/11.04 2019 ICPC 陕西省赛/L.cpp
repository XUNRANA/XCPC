#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 1000000007
int f(int x)
{
	int res=1;
	if(x==0) return 0;
	while(x)
	{
		res=res*(x%10)%P;
		x/=10;
	}
	return res;
}
void solve()
{
	int l,r;
	cin>>l>>r;
	if(r-l+1>=10) cout<<"0\n";
	else
	{
		int ans=1;
		for(int i=l;i<=r;i++) ans=ans*f(i)%P;
		cout<<ans<<"\n";
	}	
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
