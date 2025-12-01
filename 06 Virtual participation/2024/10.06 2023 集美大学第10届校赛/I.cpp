#include <bits/stdc++.h>
using namespace std;
int x0,x1,x2,a0,a1,b0,b1,ans;
void solve()
{
	cin>>x0>>x1>>x2;
	cin>>a0>>a1>>b0>>b1;
	ans=0;
	if(b0==a0)
	{
		for(int i=a1;i<b1;i++)
		{
			if(i==x0||i==x1||i==x2) continue;
			ans++;
		}
		cout<<ans<<"\n";
		return ;
	}
	
	ans=(b0-a0-1)*4;
	for(int i=a1;i<=7;i++)
	{
		if(i==x0||i==x1||i==x2) continue;
		ans++;
	}
	for(int i=1;i<b1;i++)
	{
		if(i==x0||i==x1||i==x2) continue;
		ans++;
	}
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
