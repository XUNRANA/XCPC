#include <bits/stdc++.h>
using namespace std;
int n,m,dx,dy,ans;
void solve()
{
	cin>>n>>m;
	ans=n*4*m;
	for(int i=1;i<=n;i++)
	{
		cin>>dx>>dy;
		if(i!=1)
		{
			ans-=((m-dx)+(m-dy))*2;
		}
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
