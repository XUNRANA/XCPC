#include <bits/stdc++.h>
using namespace std;
int a,b,x,y,ans=1e9;
void solve()
{
	cin>>a>>b>>x>>y;
	for(int i=0;i<=20;i++)
	{
		int a1=a;
		int b1=b;
		int cnt=i;
		a1-=y*i;
		b1-=y*i;
		if(a1>0) cnt+=(a1+x-1)/x;
		if(b1>0) cnt+=(b1+x-1)/x;
		ans=min(ans,cnt);
	}
	cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

