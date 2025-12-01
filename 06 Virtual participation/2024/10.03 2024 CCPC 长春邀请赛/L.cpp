#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	int k,x,y;
	cin>>k>>x>>y;
	//x¸ö1  y¸ö2 
	if(k&1)
	{
		if(k==1)
		{
			cout<<x+y<<"\n";
			return ;
		}
		int cx=1;
		int cy=k/2;
		int ans=min(x/cx,y/cy);
		x-=ans*cx;
		y-=ans*cy;
		if(x&&!y) ans+=x/k;
		if(y&&!x) ans+=y/(cy+1);
		if(x&&y)
		{
			int t=k-2*y;
			if(x>=t)
			{
				ans++;
				x-=t;
				ans+=x/k;
			}
		}
		cout<<ans<<"\n";
	}
	else cout<<(x+2*y)/k<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}


