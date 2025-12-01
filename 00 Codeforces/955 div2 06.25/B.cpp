#include <bits/stdc++.h>
using namespace std;
#define int long long
int x,y,k;
void solve()
{
	cin>>x>>y>>k;
	while(k)
	{
		int t=y-x%y;
		if(k<=t) 
		{
			x+=k;
			while(x%y==0) x/=y;
			k=0;
		}
		else
		{
			k-=t;
			x+=t;
			while(x%y==0) x/=y;
		}
		if(x==1)
		{
			k%=y-1;
			x+=k;
			break;
		}
	}
	cout<<x<<"\n";

	
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
