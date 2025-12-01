#include <bits/stdc++.h>
using namespace std;
int la,ra,lb,rb,x,ans;
void solve()
{
	ans=0;
	cin>>la>>ra>>lb>>rb;
	if(ra-la>=10||rb-lb>=10) ans=9;
	else 
	{
		for(int i=la;i<=ra;i++)
		{
			for(int j=lb;j<=rb;j++)
			{
				x=i+j;
				while(x)
				{
					ans=max(ans,x%10);
					x/=10;
				}
			}
		}
	}
	cout<<ans<<'\n';
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>T;
	while(T--) solve();
}
