#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,l,r,x,y,ans;
void solve()
{
	cin>>n;
	cin>>l>>r;
	for(int i=1;i<n;i++)
	{
		cin>>x>>y;
		if(x>r)
		{
			ans+=x-r;
			l=r=x;
		}
		else if(y<l)
		{
			ans+=l-y;
			l=r=y;
		}
		else
		{
			l=max(l,x);
			r=min(r,y);
		}
	}
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
